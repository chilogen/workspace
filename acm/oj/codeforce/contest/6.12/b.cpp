#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL odd,n,k,sum,a,i;
	cin>>n>>k;
	sum=4*n;
	for(i=0;i<k;i++)
	{
		cin>>a;
		if(a%2==0)	sum-=a/2;
		else	sum=sum-1-(a-1)/2;
	}
	if(sum>=0)	puts("YES");
	else puts("NO");
	return 0;
}