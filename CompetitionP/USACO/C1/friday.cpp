/*
ID: opsopsp1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

void add(int array[], int day){
	array[day%7] += 1;
}

int main (int argc, char** argv) {
	ifstream in("friday.in",ios::in);
	ofstream out("friday.out",ios::out);
	if(!in) cout<< "Cannot open file!" << endl;
	
	int i=0,d=3,y=1900;
	int s[7] = {0};
	in >> i;
	while(y<1900+i){
		d += 31;
		add(s,d);
		d += 31;
		add(s,d);
		if(y%4==0){
			if(y%100==0&&y%400!=0)
				d += 28;
			else
				d += 29;
		}
		else
			d += 28;
		add(s,d);
		d += 31;
		add(s,d);
		d += 30;
		add(s,d);
		d += 31;
		add(s,d);
		d += 30;
		add(s,d);
		d += 31;
		add(s,d);
		d += 31;
		add(s,d);
		d += 30;
		add(s,d);
		d += 31;
		add(s,d);
		d += 30;
		add(s,d);
		d %=  7;
		y++;
	}
	for(int i=0;i<7;i++){
		if(i!=0) 
			out << " ";
		out << s[(i+6)%7];
	}
	out << endl;
	return 0;
}
