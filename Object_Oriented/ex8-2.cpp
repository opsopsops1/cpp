#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
	int count;
	int size = 0;
	char str[50];
	string longest,load;
	
	cout<< "Please enter input file name: " << endl;
	cin.getline(str,50,'\n');
	ifstream in(str,ios::in);
	if (!in)
	cout << "Cannot open file!" << endl;
	//----------------------------------
	while(in >> load){
		count++;
		if(load.size()>size){
			longest = load;
			size = longest.size();
		}
	}
	//----------------------------------
	cout<< "Please enter output file name: (ex8-2-out.txt)" << endl;
	cin.getline(str,100,'\n');
	ofstream out(str,ios::out);
	out << "The number of words read is " << count << endl;
	out << "The longest word has a length of " << size << endl;
	out << "The longest word is " << longest << endl;
	
	return 0;
}
