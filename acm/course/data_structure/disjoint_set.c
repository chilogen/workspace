#include<stdio.h>
#include<malloc.h>
int *set,n;
int find(int value)
{
	if(set[value]==value) return value;
	else set[value]=find(set[value]);
	return set[value];
}
void union(int parent,int children)
{
	set[children]=parent;
}
int main()
{
	scanf("%d",&n);
	set=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		set[i]=i;
	}//并查集初始化
	for(int i=0;i<5;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		union(a,b);
	}
	for(int i=0;i<5;i++)
	{
		int a;
		scanf("%d",&a);
		printf("%d\n",find(a));
		for(int j=0;j<n;j++)
			printf("%d ",set[j]);
		printf("\n");
	}
	return 0;
}
