#include <stdio.h>
int gcd(int a,int b)
{
	if(a<b)
	{
		a=a^b;	b=a^b; a=a^b;
	}
	if(a%b==0) return b;
	a=a-b*(a/b);
	return gcd(b,a);
}
int solve(double x1,double x2,double x,double y1,double y2,double y,int * i,int * j)
{	
			if(x1*y2-x2*y1==0)	return 0;

			int max,min=gcd(x1,y1);
			max=(int)(x1*y1/min);
			double k=max/x1;
			y1=0;	y2=y2-x2*k;	y=y-x*k;

			if((int)(y)%(int)(y2)==0)	
			{
				*j=(int)(y/y2);
				if((int)(x-x2*(*j))%(int)(x1)==0)
					{*i=(x-x2*(*j))/x1; return 1;}
			}
			return 0;
}

int main()
{
	int n;
	double leg1,leg2,arm1,arm2,leg,arm;
	int i,j,k;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&leg1,&arm1,&leg2,&arm2,&leg,&arm);
		if(solve(leg1,leg2,leg,arm1,arm2,arm,&i,&j))	printf("%d %d\n",i,j);
		else printf("?\n");
	}
	return 0;
}