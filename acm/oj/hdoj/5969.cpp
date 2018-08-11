#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL one=1;
LL nex(LL i,LL a)
{
	LL j,c;
	for(j=i;j>=0;j--)
	{
		c=a&(one<<j);
		if(c==0)	return j;
	}
	return j;
}
int main()
{
	LL t,l,r,a,b,c,d,b1,b2,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>l>>r;
		//if(l==r)	{cout<<l<<endl;	continue;}
		b1=b2=0;
		a=l;	b=r;
		while(a>0)
		{
			b1++;
			a=a>>1;
		}
		while(b>0)
		{
			b2++;
			b=b>>1;
		}
		if(b1!=b2)
		{
			j=0;
			for(i=0;i<b2;i++)
			{
				j=j^(one<<i);
			}
			cout<<j<<endl;
			continue;
		}
		else
		{
			for(j=b2-1;j>=0;j--)
			{
				c=l&(one<<j);
				d=r&(one<<j);
				if(c==d&&c!=0)	break;
			}
			j--;
			for(;j>=0;j--)
			{
				c=r&(one<<j);
				d=l&(one<<j);
				if(c!=0&&c!=d)	break;
			}
			j--;
			for(;j>=0;j--)
			{
				c=l&(one<<j);
				if(c==0)
					l=l^(one<<j);
			}
		}
		c=l|r;
		cout<<c<<endl;
	}
	return 0;
}