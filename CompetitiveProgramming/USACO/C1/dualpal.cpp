/*
ID: opsopsp1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char b[10]={'0','1','2','3','4','5','6','7','8','9'};

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
	ifstream in("dualpal.in", ios::in);
	ofstream out("dualpal.out", ios::out);
	if(!in) cout<< "Cannot open file!" << endl;
	
	int tb, start = 0, countDown = 0;
	string s;
	in >> countDown;
	in >> start;
	while(countDown){
		tb = 0;
		start++;
		for(int base = 2; base<11; base++){
			s = baseConvert(base, start);
			if(pal(s)) tb++;
			if(tb==2){
				countDown--;
				out << start << endl;
				break;
			}
		}
	}
	return 0;
}
