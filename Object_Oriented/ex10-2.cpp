#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Score{
protected:
	int *sc;
public:
	Score(){sc=new int [5];}
};
class Test:public Score{
public:	
	Test():Score(){}
	int ave(){
		int a = 0;
		for(int i=0;i<5;i++)
			a+=sc[i];
		return a/5;
	}
};
class Sport:public Score{
public:
	Sport():Score(){}
	int add(){
		int a = 0;
		for(int i=0;i<5;i++)
			a+=sc[i];
		return a*5;
	}	
};
class Evaluation: public Test, public Sport{
public:
	Evaluation(){}
	void setSco(int s[]){
		for(int i=0;i<5;i++)
			Test::sc[i]=s[i];
		for(int i=0;i<5;i++)
			Sport::sc[i]=s[i+5];
	}
	inline int stuAv(){return (Test::ave()+Sport::add());}
};
class Student{
	int id;
	string name;
	Evaluation finalScore;
public:
	void setId(int a){id=a;}
	void setName(string b){name=b;}
	int  disID(){return id;}
	string disName(){return name;}
	
	void setScore(int s[]){
		finalScore.setSco(s);
	}
	int disScore(){
		return finalScore.stuAv();
	}
	
};
class school{
	Student *stu;
	int number;
	double totalAve;
public:
	school(char c[]);
	void report(char c[]);
};
school::school(char c[]) {
	int index=0;
	int num,sid;
	int sc[10];
	string snam;
	totalAve=0;
	
	ifstream in(c,ios::in);
	if(!in) cout<< "Cannot open file!" << endl;
	in >> num;
	number=num;
	stu = new Student[num];
	
	while(num--){
		in >> sid;
		in >> snam;
		stu[index].setId(sid);
		stu[index].setName(snam);
		for(int i=0;i<10;i++)
			in >> sc[i];
		stu[index++].setScore(sc);
	}
}
void school::report(char c[]){
	int index=0;
	int num=number;

	ofstream out(c,ios::out);
	while(num--){
	out << stu[index].disID() << " ";
	out << stu[index].disName() << " ";
	out << stu[index].disScore() << endl;
	totalAve+=stu[index++].disScore();
	}
	out << "Average: " << totalAve/5;
}
int main(int argc , char* argv[]){
	school nctu(argv[1]);
	nctu.report(argv[2]);
	return 0;
}
