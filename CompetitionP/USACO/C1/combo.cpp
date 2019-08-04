/*
ID: opsopsp1
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main (int argc, char** argv) {
	ifstream in("combo.in",ios::in);
	ofstream out("combo.out",ios::out);
	if(!in) cout<<"Cannot open file!"<< endl;
	
	vector<int> FJC(3);		//combination(x,x,x)
	vector<int> masterC(3);
	vector<int>::iterator it;
	int circle=0, s=0, t1, t2, t3, repeat=0, times=0;
	in >> circle;
	for(int i=0; i<3;i++){
		in >> s;
		FJC[i]=s;
	}
	for(int i=0; i<3;i++){
		in >> s;
		masterC[i]=s;
	}in.close();
	for(int i=-2;i<3;i++){	
		t1 = FJC[0]+i-masterC[0];
		if( ((t1>2-circle && t1<-2)||(t1>2 && t1<circle-2)) ) continue;
		for(int j=-2;j<3;j++){
			t2 = FJC[1]+j-masterC[1];
			if( ((t2>2-circle && t2<-2)||(t2>2 && t2<circle-2)) ) continue;
			for(int k=-2;k<3;k++){
				t3 = FJC[2]+k-masterC[2];
				if( ((t3>2-circle && t3<-2)||(t3>2 && t3<circle-2)) ) continue;
				else repeat++;
			}
		}
	}
	times = (circle>5)?(250-repeat):(circle*circle*circle);
	out << times << endl;
	out.close();
	return 0;
}
