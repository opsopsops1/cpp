#include <iostream>
#include <iomanip>

using namespace std;

class Point2D{
private:
	int x;
	int y;
public:
	Point2D(int a=0,int b=0){x=a;y=b;}
	void setPoint(int a, int b){x=a; y=b;}
	void play(){cout << "(" << x << ", " << y << ") ";}
	bool operator>(Point2D &a){
		if(x>a.x){
			return true;}
		else if(x==a.x&&y>a.y){
			return true;}
		else{ 
			return false;}
	}
};

template<class T>
T *new1D(int n, int k=0){
	T *vec = new T [n];
	for (int i=0;i<n;i++)
		vec[i] = k;
	return vec;}
template <class T> 
void display1D(T *vec, int n){
	for (int i=0;i<n;i++)
		cout << vec[i] << " ";
	cout << endl;
}
template <>
void display1D(double *vec, int n){
	cout << fixed << setprecision(2);
	for (int i=0;i<n;i++)
		cout << vec[i] << " ";
	cout << endl;
}
template <>
void display1D(Point2D *vec, int n){
	for (int i=0;i<n;i++)
		vec[i].play();
	cout << endl;
}
template <class T> 
void display(T *vec, int n){
	for (int i=0;i<n;i++)
		cout << vec[i] << " ";
	cout << endl;
}
template <>
void display(Point2D *vec, int n){
	for (int i=0;i<n;i++)
		vec[i].play();
	cout << endl;
}
template <class T>
void rand1D(T *vec, int n){
	for (int i=0;i<n;i++)
		vec[i] = (rand()%10)+1;}
template <>
void rand1D(double *vec, int n){
	for (int i=0;i<n;i++)
		vec[i] = (double)rand()*10/RAND_MAX;}
template <>
void rand1D(char *vec, int n){
	for (int i=0;i<n;i++)
		vec[i] = (rand()%26)+97;}
template <>
void rand1D(Point2D *vec, int n){
	for (int i=0;i<n;i++)
		vec[i].setPoint(rand()%10,rand()%10);}
template <class T>
void sort1D(T *vec, int n){
	T temp;
	for (int i=0;i<(n-1);i++){
		for (int j=0;j<(n-1);j++){
			if(vec[j]>vec[j+1]){
				temp=vec[j];
				vec[j]=vec[j+1];
				vec[j+1]=temp;
}}}}


template<class T>
void analysis(int n, int k=0){
	T *vec = new1D<T>(n,k);
	rand1D<T>(vec,n);
	display1D<T>(vec,n);
	sort1D<T>(vec,n);
	display<T>(vec,n);}
	
int main(){
	int n;
	cout << "Enter n: ";
	cin >> n;
	srand(1);
	analysis<int>(n);
	analysis<double>(n);
	analysis<char>(n);
	analysis<Point2D>(n);
	return 0;}
