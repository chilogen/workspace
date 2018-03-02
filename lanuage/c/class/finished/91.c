#include<stdio.h>
int main()
{
	int loop;
	double x,n,ans=1;
	scanf("%lf%lf",&x,&n);
	double xx=x,jc=1;
	if(n<0) {printf("error"); return 0;}
	for(loop=0;loop<(int)n;loop++)
	{
		ans=ans+xx/jc;
		xx*=x;
		jc*=(loop+2);
	}
	printf("%lf",ans);
	return 0;
}
