#include <bits/stdc++.h>
using namespace std;
class point
{
	int x,y;
public:
	point(int a=0,int b=0)
	{
		x=a;y=b;
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
};
class line
{
	point s,e;
public:
	line (point a,point b)
	{
		s=a;	e=b;
	}
	int len()
	{
		return sqrt(double((s.getx()-e.getx())*(s.getx()-e.getx())+(s.gety()-e.gety())*(s.gety()-e.gety())));
	}
};
int main()
{
	point a(1,2),b(3,4);
	line c(a,b);
	cout << c.len()<<endl;
	return 0;
} 