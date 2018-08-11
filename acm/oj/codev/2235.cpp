#include<stdio.h>
int main()
{
	int a;
	double b;
	scanf("%d%lf",&a,&b);
	printf("%d",(int)(a*b/10.0)%10<5?(int)(a*b/10.0)/10*10:(int)(a*b/10.0)/10*10+10);
	return 0;
}
