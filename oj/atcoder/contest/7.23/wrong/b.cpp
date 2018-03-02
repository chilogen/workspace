#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct se
{
	LL val;
	LL ind;
}b[310];
bool cmp(se a,se b)
{
	return a.val<b.val;
}
int main()
{
	LL n,m,i,j,k,l;
	LL a[310][310];
	for(i=1;i<=300;i++)
	{
		b[i].val=0;
		b[i].ind=i;
	}
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
			b[a[i][j]].val+=(m-j);
		}
	}
	sort(b+1,b+m+1,cmp);
	set<LL>s;	LL num[310];	LL ans=400;
	for(i=1;i<=m;i++)
	{
		s.insert(b[i].ind);
		memset(num,0,sizeof(num));
		for(j=0;j<n;j++)
		{
			for(k=0;k<m;k++)
			{
				if(s.count(a[j][k])!=0)
				{
					num[a[j][k]]++;
					break;
				}
			}
		}
		for(j=1,k=0;j<=m;j++)
		{
			k=max(k,num[j]);
		}
		ans=min(ans,k);
	}
	cout<<ans<<endl;
	return 0;
}