#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n,a,b,c,s,e,m;
	bool find;
	n=0;
	scanf("%lld",&n);
        //cin>>n;
	while(n--)
	{
		find=false;
		scanf("%lld%lld",&a,&b);
                //cin>>a>>b;
		c=a*b;
		e=sqrt(c);
		if(e>1e6)	e=1e6;
		s=sqrt(e);
		while(s<=e)
		{
			if(s==e&&s*s*s!=c)	break;
			m=(s+e)>>1;
			if(m*m*m==c)
			{
				find=true;
				break;
			}
			if(m*m*m<c)
			{
				if(s==m)	s++;
				else s=m;
			}
			else e=m;
		}
		if(find)
		{
			if(a%m==0&&b%m==0)	puts("Yes");
			else puts("No");
		}
		else puts("No");
	}
	return 0;
}