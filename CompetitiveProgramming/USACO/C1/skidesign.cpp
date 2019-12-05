/*
ID: opsopsp1
PROG: skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main (int argc, char** argv) {
	ifstream in("skidesign.in",ios::in);
	ofstream out("skidesign.out",ios::out);
	if(!in) cout<<"Cannot open file!"<< endl;
	
	int ev, min, max, d=0, cost=0, minCost=0, num=0;
	in >> num;
	vector<int> m(0);
	vector<int>::iterator it;
	
	for(int i=0; i<num; i++){
		in >> ev;
		if(i==0) m.push_back(ev);
		else{
			for(it =m.begin(); it!=m.end(); it++)
				if(ev < *it) break;
			m.insert(it, ev);
		}
	}
	in.close();
	min = m[0];
	max = m[num-1];
	d = max - min - 17;
	if(max-min > 17){
		for(int j=0; j<=d; j++){
			cost = 0;
			for(it =m.begin(); it!=m.end(); it++){
				if(*it < min+j) cost += (*it -min-j)*(*it -min-j);
				else if(*it > max-d+j) cost += (*it -max+d-j)*(*it -max+d-j);
			}
			if(j==0) minCost = cost;
			else if(cost < minCost) minCost = cost;
		}
		out << minCost << endl;
	}
	else out << 0 << endl;
	for(it =m.begin(); it!=m.end(); it++)
		cout << *it << endl;
	return 0;
}
