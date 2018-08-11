#include <bits/stdc++.h>
using namespace std;
#define reset(a,b)	memset(a,b,sizeof(a))
typedef long long LL;
int main()
{
	LL x1,x2,x3,y1,y2,y3,z1,z2,z3,x,y,z;
	cin>>x1>>y1>>z1;
	cin>>x2>>y2>>z2;
	cin>>x3>>y3>>z3;
	if(x1>=x2&&x1<=x3)	x=0;
	else if(x1<x2)	x=(x2-x1)*(x2-x1);
	else if(x1>x3)	x=(x1-x3)*(x1-x3);

	if(y1>=y2&&y1<=y3)	y=0;
	else if(y1<y2)	y=(y2-y1)*(y2-y1);
	else if(y1>y3)	y=(y1-y3)*(y1-y3);

	if(z1>=z2&&z1<=z3)	z=0;
	else if(z1<z2)	z=(z2-z1)*(z2-z1);
	else if(z1>z3)	z=(z1-z3)*(z1-z3);
	cout<<x+y+z<<endl;
	return 0;
}