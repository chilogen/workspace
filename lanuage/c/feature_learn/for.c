#include <stdio.h>
int main()
{
	int x=2,k;
	int a[4]={0,1,0,1};
	for(k=0;x>0;k++)
	{
		if(a[k]==1)	x--;
	}
	printf("%d\n",k);
	return 0;
}