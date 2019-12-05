/*
ID: opsopsp1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Friend{
	int money;
	string name;
public:
	Friend(){money = 0;}
	void setName(string n){name = n;}
	string getName(){return name;}
	void setMoney(int m){money+=m;}
	int getMoney(){return money;}
};
void sett(Friend* f,string n,int m){
	int j=0;
	do{
		if(f[j].getName()==n){
			f[j].setMoney(m);
			break;
		}
	}while(j++ >= 0);
}
int main (int argc, char** argv) {
	ifstream in("gift1.in",ios::in);
	ofstream out("gift1.out",ios::out);
	
	int num=0;
	string n;
	if(!in) cout<< "Cannot open file!" << endl;
	in >> num;
	Friend* fr = new Friend[num];
	for(int i=0;i<num;i++){
		in >> n;
		fr[i].setName(n);
	}
	while(in >> n){
		int m=0,d=0;
		in >> m;
		in >> d;
		if(d==0) continue;
		sett(fr,n,m%d-m);
		for(int i=0;i<d;i++){
			in >> n;
			sett(fr,n,m/d);
		}
	}
	for(int i=0;i<num;i++){
		out << fr[i].getName() << " " << fr[i].getMoney() << endl;
	}
	return 0;
}
