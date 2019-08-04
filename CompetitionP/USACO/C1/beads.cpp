/*
ID: opsopsp1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char** argv) {
	ifstream in("beads.in",ios::in);
	ofstream out("beads.out",ios::out);
	if(!in) cout<< "Cannot open file!" << endl;
	
	int a,b,max=0,num=0;
	string l,s;
	in >> num;
	in >> s;
	l = s+s+s;
	for(int i=num;i<num*2;i++){
		a=0;
		b=0;
		if(l[i] == l[i+1]) continue;
		else if(l[i]=='r' || l[i+1]=='b'){
			while(l[i-a]   != 'b') a++;
			while(l[i+1+b] != 'r') b++;
		}
		else{
			while(l[i-a]   != 'r') a++;
			while(l[i+1+b] != 'b') b++;
		}
		if((a+b)>max) max=a+b;
	}
	if(max>=num || max==0)  max=num;
	out << max << endl;
	return 0;
}
