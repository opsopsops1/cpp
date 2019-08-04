#include <iostream>
#include <cstdlib>

using namespace std;
class Point2D{
private:
	int x;
	int y;
public:
	Point2D(int a=0,int b=0){x=a;y=b;}
	void setPoint(int a, int b){x=a; y=b;}
	friend ostream &operator<<(ostream &o , const Point2D &p);
	Point2D operator+= (const Point2D &p){
		x+=p.x; y+=p.y;
		return *this;
	}
	Point2D operator* (const Point2D &p){
		x*=p.x; y*=p.y;
		return *this;
	}
};
template <class T>
class Vector{
private:
	int len;
	T* vec;
public:
	Vector(int l, int v=0){len = l; vec=new T[l]; for(int i=0;i<l;i++) vec[i]=v;}
	Vector(int l, T* v){len = l; vec=new T[l]; for(int i=0;i<l;i++) vec[i]=v[i];}
	void display(){
		for(int i=0;i<len;i++)
			cout<< vec[i] << " ";
		cout<< endl;
	}
	Vector<T> operator+=(const Vector<T> &a);
	template<class S>
	friend S dot (const Vector<S> &, const Vector<S> &);
};
template <>
class Vector<Point2D>{
private:
	int len;
	Point2D* vec;
public:
	Vector(int l, int v=0){len = l; vec=new Point2D[l]; for(int i=0;i<l;i++) vec[i].setPoint(v,v);}
	Vector(int l, Point2D* v){len = l; vec=new Point2D[l]; vec=v;}
	void display(){
		for(int i=0;i<len;i++)
			cout<< vec[i] << " ";
		cout<< endl;
	}
	Vector<Point2D> operator+=(const Vector<Point2D> &a);
	friend Point2D dot(const Vector<Point2D> &, const Vector<Point2D> &);
};
template<class T>
Vector<T> Vector<T>::operator+=(const Vector<T> &a){
	for(int i=0;i<len;i++)
		vec[i]+=a.vec[i];
	return *this;
}
Vector<Point2D> Vector<Point2D>::operator+=(const Vector<Point2D> &a){
	for(int i=0;i<len;i++)
		vec[i]+=a.vec[i];
	return *this;
}
template<class S>
S dot(const Vector<S> &x, const Vector<S> &y){
	S d;
	for(int i=0;i<x.len;i++)
		d+=x.vec[i]*y.vec[i];
	return d;
}
Point2D dot (const Vector<Point2D> &x, const Vector<Point2D> &y){
	Point2D p;
	for(int i=0;i<x.len;i++)
		p+=x.vec[i]*y.vec[i];
	return p;
}
ostream &operator<<(ostream &o , const Point2D &p){
	o << "("<< p.x << " " << p.y << ") ";
}

template<class T>
void rand1D(T *vec, int n){
	for (int i=0;i<n;i++)
		vec[i] = (rand()%10)+1;}
template<>
void rand1D(Point2D *vec, int n){
	for (int i=0;i<n;i++)
		vec[i].setPoint(rand()%10,rand()%10);}
		

int main(){
	int n;
	cout << "Enter n: ";
	cin >> n;
	Vector<double> dvec(n,1);

	double *b = new double[n];
	for (int i=0;i<n;i++) b[i] = i;

	Vector<double> dvec2(n,b);
 	cout << "dvec = "; dvec.display();
	cout << "dvec2 = "; dvec2.display();
	dvec2 += dvec;
	cout << "new dvec = "; dvec2.display();

 	double c = dot(dvec, dvec2);
 	cout << "dot(dvec, dvec2) = " << c << endl << endl;
 	srand(1);
 	Point2D *v = new Point2D[n];
 	rand1D<Point2D>(v,n); //0~9
 	Vector<Point2D> vp1(n,1);
 	Vector<Point2D> vp2(n,v);

 	cout << "vp1 = "; vp1.display();
 	cout << "vp2 = "; vp2.display();

 	vp2 += vp1;
 	cout << "new vp2 = "; vp2.display();

 	Point2D d = dot(vp1, vp2);
	cout << "dot(vp1, vp2) = " << d << endl;
 	return 0;
} 
