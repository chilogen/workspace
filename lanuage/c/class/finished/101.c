#include<stdio.h>
int main()
{
	int i,j;
	scanf("%d%d",&i,&j);
	if(j>0) i=i<<j;
	else i=i>>-j;
	printf("%d",i);
	return 0;
}
