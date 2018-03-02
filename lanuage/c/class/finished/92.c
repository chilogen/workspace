#include<stdio.h>
int main()
{
	unsigned int m,x=1;
	int k=0;
	scanf("%u",&m);
	if(m>2) m=m/2;
	if(m==1){printf("0"); return 0;}
	while(x<=m)
	{
		x=x*2;
		k++;
	}
	printf("%d",k);
	return 0;
}
