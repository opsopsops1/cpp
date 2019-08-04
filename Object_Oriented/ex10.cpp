#include <iostream>

using std::cout; using std::endl;

class Point2D{
private:
	int x;
	int y;
public:
	Point2D(){x=0;y=0;}
	Point2D(int a, int b){x=a;y=b;}
	void Pset(int a, int b){x=a;y=b;}
	int getx(){return x;}
	int gety(){return y;}
	void display() const{cout<< x << " , " << y << endl;}
};

class Shape{
protected:
	int color;
};

class Circle: public Shape{
private:
	Point2D center;
	double radius;
public:
	Circle(Point2D a, double r){
		center = a;	radius = r;
	}
	void draw(){
		cout<< "Center: ";center.display();
		cout<< "radius: " << radius << endl;
	}
	double area(){
		return (radius*radius*3.14);
	}
};
class Triangle: public Shape{
private:
	Point2D *vertices;
public:
	Triangle(Point2D *v){vertices = v;}
	~Triangle(){delete [] vertices;}
	void draw(){
		cout<< "vertices: " << endl;
		vertices[0].display();
		vertices[1].display();
		vertices[2].display();
	}
	double area(){
		double one=(vertices[0].getx()-vertices[1].getx())*(vertices[0].gety()-vertices[1].gety());
		double two=(vertices[1].getx()-vertices[2].getx())*(vertices[1].gety()-vertices[2].gety());
		double thr=(vertices[2].getx()-vertices[0].getx())*(vertices[2].gety()-vertices[0].gety());
		if(one<0)
			one = -one;
		if(two<0)
			two = -two;
		if(thr<0)
			thr = -thr;
		double ar = (one+two+thr)/2;
		return ar;
	}
};
class Circle_in_Triangle: public Circle, public Triangle{
public:
	Circle_in_Triangle(const Point2D &a, double r, Point2D *v):Circle(a,r),Triangle(v){}

	void setCColor(int a){
		Circle::color=a;
	}
	void setTriColor(int a){
		Triangle::color=a;
	}
	void draw(){
		cout << "Circle's color: " << Circle::color << endl;
		cout << "Triangle's color: " << Triangle::color << endl;
		Circle::draw();
		Triangle::draw();
	}
	double area(){
		double ar=Triangle::area()-Circle::area();
		return ar;
	}
};

int main(){
	Point2D p;
	Point2D *vec = new Point2D [3];
	p.Pset(2,2);
	vec[0].Pset(2,1);
	vec[1].Pset(8,1);
	vec[2].Pset(5,6);
	Circle_in_Triangle ct(p,1,vec);
	ct.setCColor(255);
	ct.setTriColor(255);
	ct.draw();
	cout << "Area of Circle: " << ct.Circle::area() << endl;
	cout << "Area of Triangle: " << ct.Triangle::area() << endl;
	cout << "Area of Circle_in_Triangle: " << ct.area() << endl;
	return 0;
}
