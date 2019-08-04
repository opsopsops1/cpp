#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class student{
	string name;
	int finalScore;
public:
	student(){
		name="0";
		finalScore=0;
	}
	void set(string na,int finalSco){
		name=na;
		finalScore=finalSco;
	}
	int getScore() const{return finalScore;}
	string getName() const{return name;}
};
int main(int argc, char *argv[]){
	int id,score;
	int num=0;
	int test=0;
	int sport=0;
	string name;
	
	ifstream infile(argv[1],ios::in);
	if(!infile) cout << "Cannot open File! " << endl;
	map<int, student> classroom;
	infile >> num;
	student stu[num];
	for(int i=0;i<num;i++){
		infile >> id;
		infile >> name;
		for(int j=0;j<5;j++){
			infile >> score;
			test+=score;
		}
		for(int k=0;k<5;k++){
			infile >> score;
			sport+=score;
		}
		score=test/5+sport*5;
		test=sport=0;
		stu[i].set(name,score);
		classroom.insert(pair<int,student>(id,stu[i]));
	}
	for (map<int,student>::const_iterator iter = classroom.begin();
		iter != classroom.end(); iter++){
		cout << "ID: " << iter->first;
		cout << " name: " << iter->second.getName();
		cout << " score: " << iter->second.getScore();
		cout << endl;
	}
	return 0;
}
