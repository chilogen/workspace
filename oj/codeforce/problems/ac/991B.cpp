#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n,a,b,na,nb,i,j,k,ans=0;
	cin>>n>>a>>b;
	for(na=1;na<n;na++)
	{
		nb=n-na;
		i=a/na,j=b/nb,k=min(i,j);
		if(k>ans)	ans=k;
	}
	cout<<ans<<endl;
	return 0;
}