// Point4D.h
#ifndef POINT4D_H
#define POINT4D_H
#include"Point2D.h"
class Point4D:public Point2D
{
private:
 	int *z;
 	int *t;
public:
	Point4D():Point2D(0,0){z = new int(0); t = new int(0);}
	Point4D(int a=0,int b=0,int c=0,int d=0):Point2D(a,b){
		z = new int;	*z=c;
		t = new int;	*t=d;
	}
	void display(){
		Point2D::display();
		cout << " , " << *z << " , " << *t;
	}
	Point4D& operator= (const Point2D& toD) {
		Point2D::operator= (toD);
		*z = 0; *t = 0;
		return *this;
	}
};
#endif
