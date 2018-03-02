#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define reset(a,b)	memset(a,b,sizeof(a))
int a[100000];
/*
int RandInt()
{
	int i=rand()*10+rand()%10;
	return i;
}
*/

extern int RandInt(int i, int j);

int exist(int *a,int num,int val)
{
	int i;
	for(i=0;i<num;i++)
		if(a[i]==val)	return 1;
	return 0;
}
void output(int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d,",a[i]);
 } 
void RandomPermutation1(int n)
{
	reset(a,0);
	int i=0,j,k;
	while(i<n)
	{
		j=RandInt(1,n);
		if(!exist(a,i,j))
			a[i]=j,i++;
	}
	output(n);
	printf("0\n");
}
void RandomPermutation2(int n)
{
	int *used=(int *)malloc(sizeof(int)*(n+1)),i,j,k;
	for(i=0;i<=n;i++)	used[i]=0;
	i=0;
	while(i<n)
	{
		j=RandInt(1,n);
		if(!used[j])
		{
			used[j]=1;
			a[i]=j;
			i++;
		}
	}
	output(n);
	printf("0\n");
	free(used);
	
}
void RandomPermutation3(int n)
{
	int i,j,k;
	for(i=0;i<n;i++)	a[i]=i+1;
	for(i=1;i<n;i++)
	{
		j=RandInt(0,i);
		k=a[i];
		a[i]=a[j];
		a[j]=k;
	}
	output(n);
	printf("0\n");
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n<0)
	{
		printf("ERROR\n");
		return 0;
	}
	RandomPermutation1(n);
	RandomPermutation2(n);
	RandomPermutation3(n);
	return 0;
}