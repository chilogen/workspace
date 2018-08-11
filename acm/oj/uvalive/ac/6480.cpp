#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define reset memset(a,b,sizeof(a))
int main()
{
	int t,a[20],i,j,k,l;
	cin>>t;
	while(t--)
	{
		for(i=0;i<20;i++)	scanf("%d",&a[i]);
		for(j=19;j>0;j--)
		{
			k=a[j]%2;
			l=a[j]/2;
			a[j]=k;
			a[j-1]+=l;
		}
		for(j=0;j<19;j++)
			printf("%d ",a[j]);
		printf("%d",a[j]);
		printf("\n");
	}

	return 0;
}