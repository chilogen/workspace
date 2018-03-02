#include <bits/stdc++.h>
using namespace std;
#define MAXN 10
int main()
{
	char b[10];
	int a[10],i,j,k,l;
	scanf("%s",b);
	for(i=0;i<MAXN;i++)	
	{
		a[i]=i;
		printf("%c",b[i]);
	}
	printf("\n");
	while(1)
	{
		k=-1;
		for(i=MAXN-1;i>0;i--)
		{
			if(a[i]<a[i-1])	continue;
			k=i-1;
			break;
		}
		if(k==-1)	break;
		l=k+1;	j=a[k+1];
		for(i=k+1;i<MAXN;i++)
		{
			if(a[i]>a[k]&&a[i]<j)
			{
				l=i;	j=a[i];
			}
		}
		swap(a[l],a[k]);
		i=k+1;j=MAXN-1;
		while(i<j)
		{
			swap(a[i],a[j]);
			i++;j--;
		}
		for(i=0;i<MAXN;i++)
			printf("%c",b[a[i]]);
		printf("\n");
	}
	return 0;
}