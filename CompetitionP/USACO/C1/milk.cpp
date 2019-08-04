/*
ID: opsopsp1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct farmer{
	int cpu;
	int unit;
};

int main (int argc, char** argv) {
	ifstream in("milk.in",ios::in);
	ofstream out("milk.out",ios::out);
	if(!in) cout<< "Cannot open file!" << endl;
	
	int needUnit=0, num=0, cost=0;
	in >> needUnit >> num;
	
	vector<farmer> milk;
	vector<farmer>::iterator it;
	
	for(int i=0; i<num; i++){
		farmer c;
		in >> c.cpu >> c.unit;
		if(i==0) milk.push_back(c);
		else{
			for(it=milk.begin(); it!=milk.end(); it++){
				if(c.cpu < it->cpu)	break;
			}
			milk.insert(it,c);
		}
	}
	for(it=milk.begin(); it!=milk.end(); it++){
		if(needUnit >= it->unit){
			needUnit -= it->unit;
			cost += it->cpu * it->unit;
		}
		else{
			cost += it->cpu * needUnit;
			break;
		}
	}
	out << cost << endl;
	
	for(it=milk.begin(); it!=milk.end(); it++)
		cout << it->cpu << " " << it->unit << endl;
	return 0;
}
