#include<stdio.h>
#include<stdlib.h>
int main()
{
	freopen("abc","w",stdout);
	int a[100000]={0};
	int n,q,i,x;
	scanf("%d%d%d",&n,&q,&x);
	printf("%d %d\n",n,q);
	srand(x);
	for(i=1;i<=n;i++)
	{
		a[i]=rand()%2;
	}
	srand(x);
	for(i=0;i<q;i++)
	{
		int x=rand()%(n-1)+1,y=rand()%(n-1)+1;
		if(a[x]==a[y]) printf("1 %d %d\n",x,y);
		else printf("0 %d %d\n",x,y);
	}
	fclose(stdout);
	return 0;
}
