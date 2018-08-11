#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct point 
{
	LL bri[1000];
	LL a;
}p[101][101];
LL n,q_num,c;
LL sum[101][101];
struct query
{
	LL t,x1,y1,x2,y2;
}q[100010];
inline LL lowbit(LL x)	{return x&-x;}
inline void update(LL x,LL y,LL m)
{
	if(p[x][y].a==-1)	return;
	LL &n=p[x][y].a,su=0,i,j,k=0,l;
	for(i=0;i<=n;i++)	su+=p[x][y].bri[i];
	m=((c+1)*100000+m)%(c+1);
	if(m!=0)
	{
		for(i=0;i<=n;i++)	
			p[x][y].bri[i]=(p[x][y].bri[i]+m)%(c+1);
		for(i=0;i<=n;i++)	
			k+=p[x][y].bri[i];
		k=k-su;
	}
	else if(m==0&&sum[x][y]==0)
		k=su;
	while(x<=100&&k)
	{
		i=y;
		while(i<=100)
		{
			sum[x][i]+=k;
			i+=lowbit(i);
		}
		x+=lowbit(x);
	}
}
inline LL getsum(LL x,LL y)
{
	LL ans=0,i;
	while(x>0)
	{
		i=y;
		while(i>0)
		{
			ans+=sum[x][i];
			i-=lowbit(i);
		}
		x-=lowbit(x);
	}
	return ans;
}
inline LL qu(query q)
{
	LL a=getsum(q.x2,q.y2),b=getsum(q.x2,q.y1-1),c=getsum(q.x1-1,q.y2),d=getsum(q.x1-1,q.y1-1);
	return a-b-c+d;
}
int main()
{
	LL i,j,k,l,x1,y1,x2,y2;
	for(i=1;i<=100;i++)	for(j=1;j<=100;j++)
		p[i][j].a=-1;
	memset(sum,0,sizeof(sum));
	cin>>n>>q_num>>c;
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&j,&k,&l);
		p[j][k].a++;
		p[j][k].bri[p[j][k].a]=l;
	}
	for(i=1;i<=100;i++)
		for(j=1;j<=100;j++)
			update(i,j,0);
	for(i=0;i<q_num;i++)
		scanf("%lld%lld%lld%lld%lld",&q[i].t,&q[i].x1,&q[i].y1,&q[i].x2,&q[i].y2);
	k=0;
	for(i=0;i<q_num;i++)
	{
		for(j=1;j<=100;j++)
			for(l=1;l<=100;l++)
				update(j,l,q[i].t-k);
		k=q[i].t;
		printf("%lld\n",qu(q[i]));
	}
	return 0;
}