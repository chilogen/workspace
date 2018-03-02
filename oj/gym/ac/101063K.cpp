#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAXNUM 10001
struct point 
{
	LL x,y,ind;
};
struct vec
{
	LL x,y;
	void assign(point &a,point &b)
	{
		x=b.x-a.x;
		y=b.y-a.y;
	}
};
bool operator *(const vec &a,const vec &b)
{
	LL z=a.x*b.y-a.y*b.x;
	if(z==0)	return false;
	else return true;
}
bool cmp(const point &a,const point &b)
{
	if(a.x==b.x)	return a.y<b.y;
	else return a.x<b.x;
}
int main()
{
	int n,i,j,k,l,m;
	point p[MAXNUM];
	int ans[MAXNUM][2];
	cin>>n;
	for(i=0;i<n;i++)	
	{
		cin>>p[i].x>>p[i].y;
		p[i].ind=i+1;
	}
	sort(p,p+n,cmp);	
	for(i=0;i<n-1;i++)
	{
		ans[i][0]=p[i].ind;
		ans[i][1]=p[i+1].ind;
	}
	vec v1,v2;
	v1.assign(p[0],p[1]);
	for(i=2;i<n;i++)
	{
		v2.assign(p[0],p[i]);
		if(v1*v2)
		{
			ans[n-1][0]=p[0].ind;
			ans[n-1][1]=p[i].ind;
			break;
		}
	}
	if(i==n)	cout<<"-1";
	else
	{
		for(i=0;i<n;i++)
			cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
	}
	return 0;
}