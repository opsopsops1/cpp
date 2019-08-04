/*
ID: opsopsp1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> d(0);
vector<int>::iterator it;

bool inVecFor(int i){
	for(it =d.begin(); it!=d.end(); it++)
		if(*it==i) return true;
	return false;
}
bool inVector(int i){
	while(1){
		if(inVecFor(i%10)){
			if(i/10 > 0) i/=10;
			else return true;
		}
		else return false;
	}
}

int main (int argc, char** argv) {
	ifstream in("crypt1.in",ios::in);
	ofstream out("crypt1.out",ios::out);
	if(!in) cout<<"Cannot open file!"<< endl;
	
	int num=0, ilt=0, temp=0, t=0, o=0, times=0;	//ilt integer less than ten
	bool f_break = false;
	in >> num;
	vector<int> mul(0);
	vector<int>  mu(0);
	
	
	for(int i=0; i<num; i++){
		in >> ilt;
		if(i==0) d.push_back(ilt);
		else{
			for(it=d.begin(); it!=d.end(); it++)
				if(ilt < *it) break;
			d.insert(it, ilt);
		}
	}in.close();
	for(it=d.begin(); it!=d.end(); it++){
		for(vector<int>::iterator toit=d.begin(); toit!=d.end(); toit++){
			for(vector<int>::iterator Eit=d.begin(); Eit!=d.end(); Eit++)
				mul.push_back(*it *100 + *toit *10 + *Eit);
			mu.push_back(*it *10 + *toit);
		}
	}
	for(vector<int>::iterator toit=mul.begin(); toit!=mul.end(); toit++){
		for(vector<int>::iterator Eit=mu.begin(); Eit!=mu.end(); Eit++){
			temp = (*toit) * (*Eit);
			if(temp > 10000){
				if(Eit==mu.begin()) f_break = true;	//over 1w to finish program
				break;
			}
			else if(!inVector(temp)) continue;
			else{
				temp = *Eit;
				t = temp/10;  t *= *toit;
				o = temp%10;  o *= *toit;
				if( inVector(t) && inVector(o) && t < 1000 && o < 1000) times++;
			}
		}
		if(f_break) break;
	}
	out << times << endl;
	out.close();
	return 0;
}
