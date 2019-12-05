/*
ID: opsopsp1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n=0;
vector<int> v;
bool isPrime (int num){		//not allow even
	for (int i=3;; i+=2)
	{
		if (num%i==0) return false;
		if (i*i >num) return true;
	}
}
void gen (int i, int odd[], int temp) {
	int t=0;
	for (int j=0; j<5; j++)
	{
		t = temp*10 + odd[j];
		if (isPrime(t))
		{
			if (i==2) v.push_back(t);
			else 
			{
				i--;
				gen(i, odd, t);
				i++;
			}
		}
	}
}

void readFile() {
	ifstream in("sprime.in",ios::in);
	if(!in) cout<<"Cannot open file!"<< endl;
	in >> n;
	in.close();
}
void cal_writeFile() {
	int t;
	int p[] = {2,3,5,7};
	int odd[] = {1,3,5,7,9};
	ofstream out("sprime.out",ios::out);
	for (int i=0; i<4; i++)
	{
		if (n < 2) out << p[i];
		else gen(n, odd, p[i]);
	}
	for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
		out << *it << endl;
	out.close();
}

int main (int argc, char** argv) {
	readFile();
	cal_writeFile();
	return 0;
}
