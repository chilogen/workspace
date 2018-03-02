#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n,k,i,j,l;
	cin>>n>>k;
	if(n==k)
	{
		puts("YES");
		return 0;
	}
	i=n/k;
	if(i%2==1)
	{
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}