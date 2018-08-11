#include <bits/stdc++.h>
using namespace std;
double w,h,x,y,vx,vy;
struct scan
{
	double t;
	int v;
}s[200010];
bool cmp(scan &a,scan &b)
{
	return a.t<b.t;
}
void get_t(double x,double v,double m,double &l,double &r)
{
	if(v==0&&(x<=0||x>=m))	r=l-1;
	else if(v>0)
	{
		l=max(l,-x/v);
		r=min(r,(m-x)/v);
	}
	else if(v<0)
	{
		l=max(l,(m-x)/v);
		r=min(r,-x/v);
	}
}
int a[200010];
int main()
{
	int kase,i,j,k,l,n,ans,cnt;
	double t1,t2;
	cin>>kase;
	while(kase--)
	{
		cin>>w>>h>>n;
		cnt=ans=0,j=1;
		s[0].t=-1000;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&x,&y,&vx,&vy);
			t1=0;	t2=1e9;
			get_t(x,vx,w,t1,t2);
			get_t(y,vy,h,t1,t2);
			if(t1<t2)
			{
				s[j].t=t1;	s[j].v=1;
				j++;
				s[j].t=t2;	s[j].v=-1;
				j++;
			}
			
		}
		sort(s,s+j,cmp);
		memset(a,0,sizeof(a));
		for(k=1,l=-1;k<j;k++)
		{
			if(s[k].t!=s[k-1].t)	l++;
			a[l]+=s[k].v;
		}
		for(k=0;k<=l;k++)
		{
			cnt+=a[k];
			ans=max(ans,cnt);
		}
		cout<<ans<<endl;
	}
	return 0;
}