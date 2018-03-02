#include<stdio.h>
typedef struct clock
{
	int hour;
	int minute;
	int second;
}CLOCK;
int main()
{
	CLOCK a;
	scanf("%d,%d,%d",&a.hour,&a.minute,&a.second);
	if((a.hour>24)|(a.minute>60)|(a.second>60)){printf("error"); return 0;}
	if(a.hour<10) printf("0%d:",a.hour);
	else printf("%d:",a.hour);
	if(a.minute<10) printf("0%d:",a.minute);
        else printf("%d:",a.minute);
	if(a.second<10) printf("0%d",a.second);
        else printf("%d",a.second);
	return 0;
}
