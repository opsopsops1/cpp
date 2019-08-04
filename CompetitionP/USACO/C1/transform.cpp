/*
ID: opsopsp1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool rotation090(char** b, char** a, int num){
	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			if(b[i][j] != a[j][num-1-i]) return false;
		}
	}
	return true;
}
bool rotation180(char** b, char** a, int num){
	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			if(b[i][j] != a[num-1-i][num-1-j]) return false;
		}
	}
	return true;
}
bool rotation270(char** b, char** a, int num){
	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			if(b[i][j] != a[num-1-j][i]) return false;
		}
	}
	return true;
}
bool reflection(char** b, char** a, int num){
	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			if(b[i][j] != a[i][num-1-j]) return false;
		}
	}
	return true;
}
bool combination(char** b, char** a, int num){
	bool t1=true, t2=true, t3=true;
	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			if(t1 && b[i][num-1-j] != a[j][num-1-i]){
				t1=false;
				break;
			}
		}
	}
	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			if(t2 && b[i][num-1-j] != a[num-1-j][i]){
				t2=false;
				break;
			}
		}
	}
	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			if(b[i][num-1-j] != a[num-1-i][num-1-j]){
				t3=false;
				break;
			}
		}
	}
	if(t1 || t2 || t3) return true;
	else return false;
}
bool noChange(char** b, char** a, int num){
	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			if(b[i][j] != a[i][j]) return false;
		}
	}
	return true;
}

int main (int argc, char** argv) {
	ifstream in("transform.in",ios::in);
	ofstream out("transform.out",ios::out);
	if(!in) cout<< "Cannot open file!" << endl;
	
	int num = 0;
	string s;
	in >> num;
	char **beforMatrix = new char* [num];
	char **afterMatrix = new char* [num];
	for(int i=0; i<num; i++) beforMatrix[i] = new char[num];
	for(int i=0; i<num; i++) afterMatrix[i] = new char[num];
	for(int i=0; i<num; i++){
		in >> s;
		for(int j=0; j<num; j++) beforMatrix[i][j]=s[j];
	}
	for(int i=0; i<num; i++){
		in >> s;
		for(int j=0; j<num; j++) afterMatrix[i][j]=s[j];
	}
	if(rotation090(beforMatrix, afterMatrix, num)) out << 1;
	else if(rotation180(beforMatrix, afterMatrix, num)) out << 2;
	else if(rotation270(beforMatrix, afterMatrix, num)) out << 3;
	else if(reflection(beforMatrix, afterMatrix, num))  out << 4;
	else if(combination(beforMatrix, afterMatrix, num)) out << 5;
	else if(noChange(beforMatrix, afterMatrix, num)) out << 6;
	else out << 7;
	out << endl;
	for(int i=0; i<num; i++) delete[] beforMatrix[i];
	for(int i=0; i<num; i++) delete[] afterMatrix[i];
	delete[] beforMatrix;
	delete[] afterMatrix;
	return 0;
}
