/*
ID: opsopsp1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

#define size 1000001
using namespace std;

int main (int argc, char** argv) {
	ifstream in("milk2.in",ios::in);
	ofstream out("milk2.out",ios::out);
	if(!in) cout<< "Cannot open file!" << endl;
	int num,l,r,x=0,y=0,start=0,end=0;
	int t=0,f=0,l_t=0,l_f=0;
	in >> num;
	
	bool milk[size]={false};
	l=size;
	r=0;
	while(num--){
		in >> start >> end;
		if(start<l) l=start;
		if(end>r)   r=end;
		if(y>start&&y<end&&start>x) start=y;
		if(x<end&&x>start&&end<y) end=x;
		for(int i=start;i<end;i++)
			milk[i]=true;
		x=start;
		y=end;
	}
	for(int j=l;j<(r+1);j++){
		if(milk[j]==true){
			t++;
			if(f){
				if(f>l_f) l_f=f;
				f=0;
			}
		}
		else{
			f++;
			if(t){
				if(t>l_t) l_t=t;
				t=0;
			}
		}
	}
	out << l_t << " " << l_f << endl;
	return 0;
}
