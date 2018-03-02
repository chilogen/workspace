#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAX=1e9;
int main()
{
	LL x,i,j,k,ans=0;
	cin>>x;
	while(x>1)
	{
		if(x%2==0)	x=x>>1;
		else
		{
			ans++;
			x--;
			x=x>>1;
		}
	}
	cout<<ans+1<<endl;
	return 0;
}