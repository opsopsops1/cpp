/*
ID: opsopsp1
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>

#define MAX(a,b) (a>b?(a):(b))

using namespace std;

int main (int argc, char** argv) {
	ifstream in("numtri.in",ios::in);
	ofstream out("numtri.out",ios::out);
	if(!in) cout<<"Cannot open file!"<< endl;
	
	int **tri;
	int i, j, n = 0;
	in >> n;
	tri = new int*[n];
	for (i=0; i<n; i++)
	{
		tri[i] = new int[n];
	}
	for (i=0; i<n; i++)
	{
		for (j=0; j<=i; j++)
		{
			in >> tri[i][j];
		}
	}
	
	for (i=n-2; i>=0; i--)
	{
		for (j=0; j<=i; j++)
		{
			tri[i][j] += MAX(tri[i+1][j], tri[i+1][j+1]);
		}
	}
	out << tri[0][0] << endl;
	for (i=0; i<n; i++)
	{
		delete[] tri[i];
	}
	delete[] tri;
	out.close();
	return 0;
}
