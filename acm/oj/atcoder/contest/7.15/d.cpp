#include <bits/stdc++.h>
using namespace std;
#define reset(a,b) memset(a,b,sizeof(a))
typedef long long LL;
struct edge
{
	LL u,v;
}e[200001];
LL fir[100001],nex[200001];
queue<LL>f,s,tmp;
int main()
{
	LL n,x,y,i,j,k,pain;
	bool find=false;
	LL a[100001];
	reset(a,-1);
	reset(fir,-1);
	reset(nex,-1);
	cin>>n;
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&x,&y);
		if(fir[x]!=-1)
			nex[i]=fir[x];
		fir[x]=i;
		e[i].u=x;	e[i].v=y;
		if(fir[y]!=-1)
			nex[i+n-1]=fir[y];
		fir[y]=n+i-1;
		e[i+n-1].u=y;	e[i+n-1].v=x;
	}
	f.push(1);	s.push(n);
	a[1]=1;	a[n]=0;
	n-=2;
	if(n==0)	{puts("Snuke");	find=true;	return 0;}
	x=y=0;
	while(n>0&&!find)
	{
		pain=0;
		while(!f.empty()&&!find)
		{
			i=f.front();
			i=fir[i];
			f.pop();
			k=nex[i];
			if(a[e[i].v]==-1)	
			{
				a[e[i].v]=1;
				pain++;
				n--;
				if(n==0)	{find=true;	break;}
				tmp.push(e[i].v);
			}
			while(k!=-1&&!find)
			{
				if(a[e[k].v]==-1)	
				{
					a[e[k].v]=1;
					pain++;
					n--;
					if(n==0)	{find=true;	break;}
					tmp.push(e[k].v);
				}
				k=nex[k];
			}
		}
		f=tmp;
		while(!tmp.empty())	tmp.pop();
		x+=pain;
		pain=0;
		while(!s.empty()&&!find)
		{
			i=s.front();
			i=fir[i];
			s.pop();
			k=nex[i];
			if(a[e[i].v]==-1)	
			{
				a[e[i].v]=0;
				pain++;
				n--;
				if(n==0)	{find=true;	break;}
				tmp.push(e[i].v);
			}
			while(k!=-1&&!find)
			{
				if(a[e[k].v]==-1)	
				{
					a[e[k].v]=0;
					pain++;
					n--;
					if(n==0)	{find=true;	break;}
					tmp.push(e[k].v);
				}
				k=nex[k];
			}
		}
		s=tmp;
		while(!tmp.empty())	tmp.pop();
		y+=pain;
	}
	if(x>y)	puts("Fennec");
	else puts("Snuke");
	return 0;
}