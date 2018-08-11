#include <bits/stdc++.h>
using namespace std;
typedef long LL;
struct point
{
	LL x,y;
};
int main()
{
	LL n,m,i,j,k,l;
	point p[1010],p1,p2,p3,p4;
	char a[110][110];
	cin>>n>>m;
	for(i=0;i<n;i++)
		scanf("%s",a[i]);
	l=0;
	p[0].x=p[0].y=-1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='B')
			{
				p[l].x=i;
				p[l].y=j;
				l++;
			}
		}
	}
	if(l==0)
	{
		cout<<"1"<<endl;
		return 0;
	}
	p1.x=n-1;	p1.y=m-1;
	p2.x=n-1;	p2.y=0;
	p3.x=0;		p3.y=m-1;
	p4.x=0;		p4.y=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='B')
			{
				if(i<p1.x||j<p1.y)	{p1.x=i;	p1.y=j;}
				if(i<p2.x||j>p2.y)	{p2.x=i;	p2.y=j;}
				if(i>p3.x||j<p3.y)	{p3.x=i;	p3.y=j;}
				if(i>p4.x||j>p4.y)	{p4.x=i;	p4.y=j;}
			}
		}
	}
	LL len;
	len=max((max(p3.x,p4.x)-min(p1.x,p2.x)),(max(p2.y,p4.y)-min(p1.y,p3.y)))+1;
	LL ans=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(a[i][j]=='B')
				ans++;
	if(ans==0)	
	{
		cout<<"1"<<endl;
		return 0;
	}
	if(len>n||len>m)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	ans=len*len-ans;
	cout<<ans<<endl;
	return 0;
}