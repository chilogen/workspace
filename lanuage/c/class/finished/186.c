#include<stdio.h>
int main()
{
	int num=2,sum=2;
	float cost=0.0,days=0.0;
	while(sum<100)
	{
		cost=cost+num*0.8;
		days++;
		num=num*2;
		sum+=num;
	}
	printf("%.2f",cost/days);
	return 0;
}
