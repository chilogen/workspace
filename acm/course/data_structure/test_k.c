#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int que[100001],order[100000];
long long int power[100000];
int main()
{
	int n,i;
	freopen("abc","w",stdout);
	scanf("%d%d",&n,&i);
	srand(i);
	printf("%d\n",n);
	for(i=0;i<n;i++)
	{
		power[i]=rand()%100001;
		printf("%lld ",power[i]);
	}
	printf("\n");
	for(i=1;i<=n;i++)
	{
		que[i]=i;
	}
	for(i=0;i<n;i++)
	{
		int temp=rand()%(n+1)-i;
		order[i]=que[temp];
		printf("%d ",temp);
		que[temp]=que[n-i];
	}
	printf("\n");
	fclose(stdout);
	return 0;
}