#include <bits/stdc++.h>
using namespace std;
typedef long LL;
int main()
{
	LL n,a,b,c=0,i,j,ans=0;
	cin>>n>>a>>b;
	for(i=0;i<n;i++)
	{
		scanf("%ld",&j);
		if(j==1)
		{
			if(a>0)
			{
				a--;
				continue;
			}
			if(b>0)
			{
				b--;
				c++;
				continue;
			}
			if(c>0)
			{
				c--;
				continue;
			}
			ans++;
		}
		else if(j==2)
		{
			if(b>0)
			{
				b--;
				continue;
			}
			ans+=2;
		}

	}
	cout<<ans<<endl;
	return 0;
}