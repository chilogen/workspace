#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct data
{
	LL val;
	LL ind;
}a[100000];
bool cmp(const data &a,const data &b)
{
	if(a.val==b.val)
	{
		return a.ind<b.ind;
	}
	else return a.val<b.val;
}
int main()
{
	LL n,k,i,j,l,m;
	LL max;
	while(cin>>n>>k)
	{
		for(i=0;i<n;i++)
		{
			cin>>a[i].val;
			a[i].ind=i;
		}
		sort(a,a+n,cmp);
		for(i=1,j=0,m=1,max=-1;i<n;i++)
		{
			if(a[i].val==a[i-1].val)
			{
				j=j+a[i].ind-a[i-1].ind-1;
				if(j>k)
				{
					j=j-(a[i-m+1].ind-a[i-m].ind-1);
					m--;
				}
				m++;
			}
			else
			{
				if(m>max)	max=m;
				m=1;
				j=0;
			}
		}
		if(m>max)	max=m;
		cout<<max<<endl;
	}
	return 0;
}