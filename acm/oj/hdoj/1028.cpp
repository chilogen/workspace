#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL a[121],way[121],i,j,k,n;
	for(i=1;i<=120;i++)	a[i]=i;
	memset(way,0,sizeof(way));
	way[0]=1;
	for(i=1;i<=120;i++)
	{
		for(j=0;j<=120;j++)
		{
			if(j-a[i]<0)	continue;
			way[j]+=way[j-a[i]];
		}
	}
	while(cin>>n)
	{
		cout<<way[n]<<endl;
	}
	return 0;
}