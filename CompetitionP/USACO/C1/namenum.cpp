/*
ID: opsopsp1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool cmp(char a, char b){
	if(a=='Q'||a=='Z') return false;
	bool r=false;
	switch(b){
		case '2':
			if(a=='A'||a=='B'||a=='C') r=true;
			break;
		case '3':
			if(a=='D'||a=='E'||a=='F') r=true;
			break;
		case '4':
			if(a=='G'||a=='H'||a=='I') r=true;
			break;
		case '5':
			if(a=='J'||a=='K'||a=='L') r=true;
			break;
		case '6':
			if(a=='M'||a=='N'||a=='O') r=true;
			break;
		case '7':
			if(a=='P'||a=='R'||a=='S') r=true;
			break;
		case '8':
			if(a=='T'||a=='U'||a=='V') r=true;
			break;
		case '9':
			if(a=='W'||a=='X'||a=='Y') r=true;
	}
	return r;
}

int main (int argc, char** argv) {		//ABE ACE
	ifstream in("namenum.in",ios::in);
	ifstream dict("dict.txt",ios::in);
	ofstream out("namenum.out",ios::out);
	if(!in) cout<< "Cannot open file!" << endl;

	bool finded=false;
	string id,s;
	in >> id;
	int f=0, l=id.size();
	in.close();
	while(dict >> s){
		if(s.size() != l) continue;
		if(cmp(s[0], id[0] )) f=1;
		else{
			if(f){
				if(!finded)	out << "NONE" << endl;
				break;
			}
			else continue;
		} 
		for(int i=1;i<l;i++){
			if(cmp(s[i], id[i])){
				if(i==(l-1)){
					out << s << endl;
					finded = true;
				}
			}
			else break;
		}
	}
	dict.close();
	return 0;
}
