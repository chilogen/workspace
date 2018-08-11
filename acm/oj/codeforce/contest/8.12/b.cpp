#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,a;
int main()
{
	cin>>n>>k;
	LL i,j,four,two;
	four=n;	two=2*n;
	for(i=0;i<k;i++)
	{
		cin>>a;
		j=a/4;
		if(four-j>=0)	four-=j;
		else
		{
			j=four;
			four=0;
		}
		a-=(4*j);
		j=a/2;
		two-=j;
		a-=(2*j);
		if(a)	two--;
	}
	if(four>=0&&two>=0)	puts("YES");
	else puts("NO");
	return 0;
}