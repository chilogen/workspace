#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	i=1;
	while(i<=n)
	{
		i=i<<1;
	}
	cout<<(i>>1)<<endl;
	return 0;
}