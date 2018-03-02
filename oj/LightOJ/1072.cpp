#include <bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0),eps=1e-9;
int main()
{
	int t,i,j,k;
	double R,n,the,cosa,mi,ma,r,a,b,c;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		scanf("%lf%lf",&R,&n);
		the=2*pi/n;
		cosa=cos(the);
		mi=0;	ma=R;
		while(ma-mi>eps)
		{
			r=(ma+mi)/2;
			a=R*R-2*R*r;
			b=r*r;
			c=(a-b)/(a+b);
			if(fabs(c-cosa)<eps)
			{
				printf("Case %d: ",i);
				printf("%.7lf\n",r);
				break;
			}
			else if(c-cosa>eps)	mi=r;
			else if(c-cosa<-eps)	ma=r;
		}
	}
	return 0;
}