#include <bits/stdc++.h>
#define reset(a,b)	memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
struct ans
{
	LL a,b;
}d[100];
inline void infr(LL &a,LL &b)
{
	LL j=__gcd(a,b);
	a=a/j;	b=b/j;
}
int main()
{
	LL n,m,i,j,k,t,p,q,lcm;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		j=m/2;
		if(m==1)
		{
			cout<<n<<"/"<<n+m<<endl;
			continue;
		}
		for(i=0,k=0,p=n,q=m+n;;i++)
		{
			d[k].a=p;	d[k].b=q;	
			infr(d[k].a,d[k].b);
			k++;

			p=p/n;	q=q/(m+n);

			if(m<=1)	break;

			p=p*m;	q=q*(m+n);	m--;
			infr(p,q);
			p=p*m;	q=q*(m+n);	m--;
			infr(p,q);
			p=p*n;
			q=q*(n+m);
		}
		for(i=0,p=1,q=1;i<k-1;i++)
		{
			j=__gcd(d[i].b,d[i+1].b);
			lcm=d[i].b/j*d[i+1].b;
			d[i+1].a=d[i].a*(lcm/d[i].b)+d[i+1].a*(lcm/d[i+1].b);d[i+1].b=lcm;
			infr(d[i+1].a,d[i+1].b);	
		}
		infr(d[k-1].a,d[k-1].b);
		p=d[k-1].a;	q=d[k-1].b;
		cout<<p<<"/"<<q<<endl;
	}
	return 0;
}