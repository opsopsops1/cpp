/*
ID: opsopsp1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char** argv) {
	ifstream in("ride.in",ios::in);
	ofstream out("ride.out",ios::out);
	int i = 0;
	int X[2] = {1,1};
	string str;
	
	if (!in)
		cout<< "Cannot open file!" << endl;
	while(in >> str){
		for(int j=0;j<str.size();j++)
			X[i]=X[i]*(str[j]-64);
		i=i+1;
	}
	cout << X[0]; 
	cout << X[1];
	if((X[0]%47)==(X[1]%47))
		out << "GO" << endl;
	else
		out << "STAY" << endl;
	
	return 0;
}
