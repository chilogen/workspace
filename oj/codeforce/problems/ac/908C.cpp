#include <bits/stdc++.h>
using namespace std;
int n;
double r,x[1010],y[1010];
inline double calc(double x1,double y1,double x)
{
	return y1+sqrt(4*r*r-(x-x1)*(x-x1));
}
int main()
{
	int i,j,k;
	cin>>n>>r;
	for(i=0;i<n;i++)	y[i]=-1;
	for(i=0;i<n;i++)	cin>>x[i];
	for(i=0;i<n;i++)
	{
		for(j=i-1;j>=0;j--)
			if(abs(x[i]-x[j])<=2*r)	y[i]=max(y[i],calc(x[j],y[j],x[i]));
		y[i]=max(y[i],r);
	}
	for(i=0;i<n;i++)	printf("%.10f ",y[i]);
	return 0;
}