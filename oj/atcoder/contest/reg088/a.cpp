#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b,i;
int main()
{
	cin>>a>>b;
	i=0;
	while(a<=b)
	{
		a=a<<1;
		i++;
	}
	cout<<i<<endl;
	return 0;
}