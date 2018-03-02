#include<stdio.h>
int main()
{
	int lop,n,k;
	scanf("%d",&n);
	k=n;
	for(lop=0;lop<4;lop++)
	{
		printf("%d ",k);
		k=k*n;
	}
	printf("%d\n",k);
	return 0;
}
