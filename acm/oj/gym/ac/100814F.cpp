#include  <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL t,w,h;
	cin>>t;
	while(t--)
	{
		cin>>w>>h;
		if(w==h)	puts("Square");
		else puts("Rectangle");
	}
	return 0;
}