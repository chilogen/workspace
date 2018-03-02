#include<stdio.h>
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
int solve(int x1,int x2,int x,int y1,int y2,int y,int * i,int * j)
{	
			if(x1*y2-x2*y1==0)	return 0;

			int max,min=gcd(x1,x2);
			max=x1*x2/min;
			int k=max/x2;
			x2=max;	y2=k*y2;	y=k*y;
			if(y%y2==0)	
			{
				*j=y/y2;
				if((x-y1*(*j))%x1==0)
					{*i=(x-y1)*(*j)/x1; return 1;}
			}
}
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	int i,j;
	if(solve(a,b,c,d,e,f,&i,&j))
	{
		printf("%d %d",i,j);
	}
	else printf("?\n");
	return 0;
}