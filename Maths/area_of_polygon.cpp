#include<bits/stdc++.h>
using namespace std;

struct point
{
	double x;
	double y;
};

double area(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - x2 * y1;    // cross product
}

int main()
{
	point p[100];
	double sum = 0;
	int n;
	cout<<"enter number of side: ";
	cin>>n;
	cout<<"enter co-ordinates: ";
	
	for(int i = 0; i < n; i++)
	{
		cin>>p[i].x>>p[i].y;
	}

	for(int i = 0; i < n; i++)
	{
		sum += sum + area(p[i].x , p[i].y, p[(i+1)%n].x, p[(i+1)%n].y);
	}

	cout<<"area: "<<abs(sum / 2)<<endl;  // abs is because of direction area could be negative for clockwise
	return 0;
}
