/*
ID: opsopsp1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char b[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};

bool pal(string s){
	if(s.length()==0 || s.length()==1) return true;
	else{
		if (s[0] != s[s.length()-1]) return false;
		else{
			string c=s;
			c.erase(c.begin());
			c.erase(c.end()-1);
			return pal(c);
		}
	}
}

string baseConvert(int base, int i){
	string s = "";
	while(i/base > 0){
		s = b[i%base] + s;
		i /= base;
	}
	s = b[i] + s;
	return s;
}


int main (int argc, char** argv) {
	ifstream in("palsquare.in", ios::in);
	ofstream out("palsquare.out", ios::out);
	if(!in) cout<< "Cannot open file!" << endl;
	
	int base = 0;
	string sq = "";
	in >> base;
	in.close();
	for(int i = 1; i < 301; i++){
		sq = baseConvert(base, i*i);
		if(pal(sq))	out << baseConvert(base, i) << " " << sq << endl;
	}
	return 0;
}
