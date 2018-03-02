#include <bits/stdc++.h>
using namespace std;
#define reset(a,b)	memset(a,b,sizeof(a))
typedef long long LL;
struct point
{
	LL x,y;
}p1,p2;
struct vec
{
	point a,b;
	LL d;
}v[5010];
inline LL dist(point a,point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool operator ==(point a,point b)
{
	if(a.x==b.x&&a.y==b.y)	return true;
	else return false;
}
int main()
{
	freopen("lshape.in","r",stdin);
	freopen("lshape.out","w",stdout);
	LL n,i,j,k,ans=0;
	LL d1,d2;
	cin>>n;
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&p1.x,&p1.y);
		scanf("%lld%lld",&p2.x,&p2.y);
		v[i].a=p1;	v[i].b=p2;
		v[i].d=dist(p1,p2);
		if(v[i].d==0){i--;n--;}
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			
			if(v[i].a==v[j].a)
			{
				if(dist(v[i].b,v[j].b)==v[i].d+v[j].d)
					ans++;
			}
			else if(v[i].a==v[j].b)
			{
				if(dist(v[i].b,v[j].a)==v[i].d+v[j].d)
					ans++;

			}
			else if(v[i].b==v[j].b)
			{
				if(dist(v[i].a,v[j].a)==v[i].d+v[j].d)
					ans++;

			}
			else if(v[i].b==v[j].a)
			{
				if(dist(v[i].a,v[j].b)==v[i].d+v[j].d)
					ans++;

			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}