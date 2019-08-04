// Point2D.h
#ifndef POINT2D_H
#define POINT2D_H
using std::cout;
class Point2D{
 	int *x;
 	int *y;
public:
	Point2D(){x = new int(0); y = new int(0);}
	Point2D(int a, int b);
	void display(){
		cout<< *x << " , " << *y;
	}
};
Point2D::Point2D(int a, int b){
	x = new int;	*x=a;
	y = new int;	*y=b;
}
#endif
