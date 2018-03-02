#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define MAXN 10010

struct query
{
	LL l,r,t,ind;
}q[MAXN];
struct tim
{
	LL pos,now,old;
}t[MAXN];
LL a[MAXN],block[MAXN],color[MAXN],sum[MAXN*100];
LL unitsize,ans=0,l=1,r=0,n,m;

bool cmp(query a,query b)
{
	return block[a.l]==block[b.l]?a.r==b.r?a.t<b.t:a.r<b.r:block[a.l]<block[b.l];
}

void updatatim(LL x,LL v)
{

	if(x>=l&&x<=r)
	{
		sum[color[x]]--;
		if(sum[color[x]]==0)	ans--;
		sum[v]++;
		if(sum[v]==1)	ans++;
	}
	color[x]=v;
}

void updata(LL x,LL flag)
{
	sum[color[x]]+=flag;
	if(sum[color[x]]==0&&flag==-1)	ans--;
	if(sum[color[x]]==1&&flag==1)	ans++;
}

int main()
{
	LL i,j,k;
	char c;
	memset(sum,0,sizeof(sum));
	cin>>n>>m;
	unitsize=pow(n,2.0/3.0);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&color[i]);
		block[i]=i/unitsize;
	}
	for(i=0,j=0,k=0;i<m;i++)
	{
		while(1)
		{
			scanf("%c",&c);
			if(c=='Q'||c=='R')	break;
		}
		if(c=='Q')
		{
			scanf("%lld%lld",&q[j].l,&q[j].r);
			q[j].ind=j;
			q[j].t=k;
			j++;
		}
		if(c=='R')
		{
			k++;
			scanf("%lld%lld",&t[k].pos,&t[k].now);
			t[k].old=color[t[k].pos];
		}
	}
	sort(q,q+j,cmp);

	k=0;
	for(i=0;i<j;i++)
	{
		while(k<q[i].t)	updatatim(t[k+1].pos,t[k+1].now),k++;
		while(k>q[i].t)	updatatim(t[k].pos,t[k].old),k--;

		while(l<q[i].l)	updata(l,-1),l++;
		while(l>q[i].l)	updata(l-1,1),l--;

		while(r<q[i].r)	updata(r+1,1),r++;
		while(r>q[i].r)	updata(r,-1),r--;

		a[q[i].ind]=ans;
	}

	for(i=0;i<j;i++)	cout<<a[i]<<endl;
	return 0;
}