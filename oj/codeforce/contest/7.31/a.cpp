#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	int s,v1,v2,t1,t2,a,b;
	cin>>s>>v1>>v2>>t1>>t2;
	a=s*v1+t1*2;
	b=s*v2+t2*2;
	if(a<b)	puts("First");
	else if(a>b)	puts("Second");
	else if(a==b)	puts("Friendship");
	return 0;
}