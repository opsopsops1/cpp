/*
ID: opsopsp1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

#define MIN(a,b) (a<b?(a):(b))

using namespace std;

//vector<int>
int b[3] = {0};		//three buckets
int full[3];
set<int> result;
set<int> c;			//C bucket

void dfs() {
	int t = b[0]*10000 + b[1]*100 + b[2];
	if (result.find(t) != result.end()) return;
	result.insert(t);
	if (b[0] == 0) c.insert(b[2]);
	
	for (int i=0; i<3; i++) 
	{
		if (b[i] != 0) 
		{
			for (int j=0; j<3; j++) 
			{
				if (i != j && b[j] < full[j])
				{
					int m = MIN(full[j] - b[j], b[i]);
					b[i] -= m;
					b[j] += m;
					dfs();
					b[i] += m;
					b[j] -= m;
				}
			}
		}
	}
}

int main (int argc, char** argv) {
	ifstream in("milk3.in",ios::in);
	ofstream out("milk3.out",ios::out);
	if(!in) cout<<"Cannot open file!"<< endl;
	
	vector<int> v;
	in >> full[0] >> full[1] >> full[2];
	b[2] = full[2];
	dfs();
	
	for (set<int>::iterator it = c.begin(); it != c.end(); it++)
	{
		v.push_back(*it);
	}
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		if (it != v.begin()) out << " ";
		out << *it;
	}
	out << endl;
	out.close();
	return 0;
}
