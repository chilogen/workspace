#include <iostream>
using namespace std;
typedef long long LL;
LL const mod=10007;
LL p(LL a,LL b)
{
	LL ans=1;
	while(b)
	{
		if(b&1)	ans=(ans*a)%mod;
		b=b>>1;
		a=(a*a)%mod;
	}
	return ans;
}
int main()
{
	LL n,i,k,j,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		i=p(2,2*(n-1))+p(2,n-1);
		cout<<i%mod<<endl;
	}
	return 0;
}