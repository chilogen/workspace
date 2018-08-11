#include<stdio.h>
#include<math.h>
int main()
{
	double a,b;
	scanf("%lf%lf",&a,&b);
	if(fabs(a-b)<1e-8) printf("yes");
	else printf("no");
	return 0;
}
