#include<bits/stdc++.h>
using namespace std;

struct point
{
	double x;
	double y;
};

double cross_product(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - x2 * y1;
}

int main()
{
	point p[3];
	cout<<"enter 1st co-odinate: ";
	cin>>p[0].x>>p[0].y;
	cout<<"enter 2nd co-odinate: ";
	cin>>p[1].x>>p[1].y;
	cout<<"enter point co-odinate: ";
	cin>>p[2].x>>p[2].y;

	// shifting first point to origin

	p[1].x = p[1].x - p[0].x;
	p[1].y = p[1].y - p[0].y;
	p[2].x = p[2].x - p[1].x;
	p[2].y = p[2].y - p[1].y;

	double ans = cross_product(p[1].x, p[1].y, p[2].x, p[2].y);

	if(ans > 0)
		cout<<"on left side";
	else if(ans < 0)
		cout<<"on right side";
	else
		cout<<"on the line";
	cout<<endl;

	return 0;
}
