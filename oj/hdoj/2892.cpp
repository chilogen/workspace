#include <bits/stdc++.h>
using namespace std;
struct point 
{
	double x,y;
};
struct line
{
	double k,d;
	double x,y;
};
struct circle
{
	double a,b,c;
};
void interset(circle o,line l)
{
	double m=o.a+l.k*(o.b-l.d);
	double n=1+l.k*l.k;
	double x1=(m+sqrt(m*m-n*(o.a*o.a-o.c*o.c)))/n;
	double x2=(m-sqrt(m*m-n*(o.a*o.a-o.c*o.c)))/n;
	double y1=l.k*x1+l.b;
	double y2=l.k*x2+l.b;
	cout<<x1<<" "<<y1<<endl;
	cout<<x2<<" "<<y2<<endl;
}
int main()
{
	circle o1;
	line l1;
	point p1;
	cin>>o1.a>>o1.b>>o1.c;
	cin>>l1.k>>l1.d;
	interset(o1,l1);
	return 0;
}