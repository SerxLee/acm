#include <iostream>
#include <cmath>
using namespace std;

#define pi acos(-1.0)

typedef struct node
{
	int x;
	int y;
}point;

double AREA(point a, double r1, point b, double r2){
	double d = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
	if (d >= r1+r2)
		return 0;
	if (r1>r2){
		double tmp = r1;
		r1 = r2;
		r2 = tmp;
	}
	if(r2 - r1 >= d)
		return pi*r1*r1;
	double ang = acos((r1*r1+d*d-r2*r2)/(2*r1*d));
	double ang2 = acos((r2*r2+d*d-r1*r1)/(2*r2*d));
	return ang1*r1*r1 + ang2*r2*r2 - r1*d*sin(ang1);
}

int main()
{
	point a, b;
	a.x=2, a.y=2;
	b.x=7, b.y=2;
	double result = AREA(a, 3, b, 5);
	printf("%lf\n", result);
	return 0;
}