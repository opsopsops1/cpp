/*
ID: opsopsp1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main (int argc, char** argv) {
	ifstream in("barn1.in",ios::in);
	ofstream out("barn1.out",ios::out);
	if(!in) cout<<"Cannot open file!"<< endl;
	
	int max, num=0, stall=0, cow=0, blank=0;
	in >> num >> stall >> cow;
	vector<int> s(cow);
	vector<int> l(0);
	vector<int>::iterator it;
	
	for(int i=0; i<cow; i++) in >> s[i];
	sort(s.begin(), s.end());
	
	for(int j=1; j<cow; j++){
		if(j==1) l.push_back(s[j]-s[j-1]);
		else{
			for(it =l.begin(); it!=l.end(); it++)
				if( s[j]-s[j-1] < *it) break;
			l.insert(it, s[j]-s[j-1]);
		}
	}
	for(int k=0; k<num-1; k++) blank = blank + l[l.size()-1-k] -1;
	if(num>=cow) out << cow << endl;
	else out << (s[cow-1] - s[0]+1 - blank) << endl;
	
	return 0;
}
