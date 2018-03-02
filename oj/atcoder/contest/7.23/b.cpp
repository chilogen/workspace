#include <bits/stdc++.h>
using namespace std;
#define reset(a,b)	memset(a,b,sizeof(a))
int main()
{
	int chos[303],num[303],a[303][303],i,j,k,l,n,m,ans=410;
	cin>>n>>m;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)	cin>>a[i][j];
	reset(chos,0);
	for(i=0;i<m;i++)
	{
		reset(num,0);
		for(j=0;j<n;j++)
			for(k=0;k<m;k++)
				if(chos[a[j][k]]==0)
				{
					num[a[j][k]]++;
					break;
				}
		for(j=1,k=0,l=0;j<=m;j++)
		{
			if(num[j]>k)
			{
				k=num[j];
				l=j;
			}
		}
		ans=min(ans,k);
		chos[l]=-1;
	}
	cout<<ans<<endl;
	return 0;
}