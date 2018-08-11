#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL p,k,a,ans;
	cin>>p;
	while(p--)
	{
		cin>>k>>a;
		ans=a;
		while(a!=1)
		{
			if(a%2==0)	a=a>>1;
			else
			{
				a=3*a+1;
				ans=max(ans,a);
			}
		}
		cout<<k<<" "<<ans<<endl;
	}
	return 0;
}