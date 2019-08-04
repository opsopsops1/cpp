#include <iostream>

using std::cout; using std::endl;

class Point2D{
private:
	int *x;
	int *y;
public:
	Point2D(){x = new int (0);y=new int (0);}
	Point2D(int a, int b){x=new int(a);y=new int(b);}
	void copy(Point2D p){*x=p.getx(); *y=p.gety();}
	int getx(){return *x;}
	int gety(){return *y;}
	void setPoint2D(int a, int b){delete x; delete y;x=new int(a);y=new int(b);}
	~Point2D(){delete x;delete y;}
	void display(){cout<<*x<<","<<*y<<endl;}
};
class Shape{
protected:
	int color;
public:
	virtual void draw() = 0;
	virtual bool is_closed() = 0;
	virtual ~Shape(){}
};
class Circle: public Shape{
private:
	Point2D center;
	double radius;
public:
	Circle(const Point2D &a, double r, int c):center(a){radius = r; color = c;}
	~Circle(){}
	
	
	void draw(){
		cout<<"Color: "<<color<<endl
			<<"Center: ";center.display();
		cout<<"Radius: "<<radius<<endl;
	}
	bool is_closed() {return true;}
};

class Polygon: public Shape{
public:
	bool is_closed() {return true;}
};
class Triangle: public Polygon{
private:
	Point2D *vertices;
public:
	Triangle(Point2D *v, int c){
		vertices=new Point2D[3];
		vertices[0].copy(v[0]);
		vertices[1].copy(v[1]);
		vertices[2].copy(v[2]);
		color =c;}
	~Triangle() {delete [] vertices;}
	void draw(){
		cout<<"Color: "<<color<<endl
			<<"Vertices"<<endl;
		for(int j=0;j<3;j++)
			vertices[j].display();
	}
};

int main(){
	Point2D pt(3,4);
	Circle c(pt,5,255);
	c.draw();
	Point2D *vec = new Point2D[3];
	vec[0].setPoint2D(1,1);
	vec[1].setPoint2D(6,1);
	vec[2].setPoint2D(1,8);
	Triangle t(vec,255);
	delete [] vec;
	t.draw();
	return 0;
}
