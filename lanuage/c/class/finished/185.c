#include<stdio.h>
int main()
{
	int year;
	scanf("%d",&year);
	if(year%10==0)
		{if(year%400==0) {printf("yes"); return 0;}}
	else    if(year%4==0&&year%100!=0) {printf("yes"); return 0;}
	printf("no");
	return 0;
}
