#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL C2(LL i)
{
	return i*(i-1)/2;
}
LL C1(LL i)
{
	return i;
}
LL C3(LL i)
{
	return i*(i-1)*(i-2)/6;
}
int main()
{
	LL n,odd,even,i,j,k,ans=0;
	cin>>n;
	odd=n>>1;	even=n>>1;
	if(n%2==1)	odd++;
	ans+=C3(even);
	ans+=C2(odd)*C1(even);
	cout<<ans<<endl;
}