#include <bits/stdc++.h>
const double pi=acos(-1);
using namespace std;
double t,n,f,r,area[10001];
int main()
{
	int i,j,k,num;
	double x,s,e;
	cin>>t;
	while(t--)
	{
		cin>>n>>f;
		e=0,num=0,s=0;
		for(i=1;i<=n;i++)
		{
			cin>>r;
			area[i]=pi*r*r;
			e=max(e,area[i]);
		}
		while(abs(s-e)>1e-6)
		{
			x=(s+e)/2.0;
			num=0;
			for(i=1;i<=n;i++)
			{
				j=area[i]/x;
				num+=j;
			}
			if(num<f+1)	e=x;
			else s=x;
		}
		printf("%.6lf\n",x);
	}
	return 0;
}