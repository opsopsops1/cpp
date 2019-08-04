#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Complex{
	double real;
	double imaginary;
public:
	Complex(){real=0; imaginary=0;}
	Complex(double a, double b){real=a; imaginary=b;}
	bool operator< (const Complex &c){
		if(real<c.real||(real==c.real&&imaginary<c.imaginary))
			return true;
		else
			return false;
	}
	friend ostream& operator<< (ostream &out, const Complex &c);
};
ostream& operator<< (ostream &out, const Complex &c){
	cout<< "(" << c.real << "," << c.imaginary << ")";
}

int main(){
	int n;
	cout<< "Enter n: " << endl;
	std::cin >> n;
	vector<Complex> vec(n);
	vector<Complex>::const_iterator iter;
	
	for(int i=0;i<vec.size();i++)
		vec[i]=Complex((double)rand()*10/RAND_MAX,(double)rand()*10/RAND_MAX);
	
	cout<< "Original sequence:" << endl;
	cout<< fixed << setprecision(1);
	for(iter=vec.begin();iter!=vec.end();iter++)
		cout<< *iter;
	cout<< endl;
	
	sort(vec.begin(),vec.end());
	cout<< "Sorted sequence:" << endl;
	for(iter=vec.begin();iter!=vec.end();iter++)
		cout<< *iter;
	
	return 0;
} 
