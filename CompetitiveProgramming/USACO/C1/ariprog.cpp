/*
ID: opsopsp1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main (int argc, char** argv) {
	ifstream in("ariprog.in",ios::in);
	ofstream out("ariprog.out",ios::out);
	if(!in) cout<<"Cannot open file!"<< endl;
	
	int len=0, bound=0, temp=0, max=0, diff=1, find=0;
	
	in >> len >> bound;
	int sq[bound+1]={0};
	int v[bound*bound*2+1]={0};
	in.close();
	vector<int> sor(0);
	vector<int>::iterator it;
	
	for(int i=0; i<=bound; i++) sq[i] = i*i;
	for(int i=0; i<=bound; i++){
		for(int j=i; j<=bound; j++)
		{
			temp = sq[i] + sq[j];
			v[temp] = 1;
		}
	}
	for(int i=0; i<=bound*bound*2; i++)
		if(v[i]) sor.push_back(i);
	
	max = temp / (len-1);
	
	while(diff <= max){
		for(int i=0; i<sor.size(); i++)
		{
			for(int j=len-1; j>=0; j--)
			{
				if(!j)
				{
					if(!find) find++;
					out << sor[i] << " " << diff << endl;
				}
				if(sor[i]+j*diff>temp) break;
				if(v[sor[i]+j*diff]==0) break;
			}	
		}
		if(len>15&&diff>=84) diff+=84;
		else{
			if(len>5&&diff>=12)  diff+=12;
			else{
				if(len>3&&diff>=4)   diff+=4;
				else diff++;
			}
		}
		//diff++;
	}
	if(!find) out << "NONE" << endl;
	out.close();
	return 0;
}
