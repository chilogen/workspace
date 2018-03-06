#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL sum[1100];
int main()
{
	LL a,b,mid,ans,i,j,k;
	cin>>a>>b;
	sum[0]=0;
	for(i=1;i<=1000;i++){
		sum[i]=i+sum[i-1];
	}
	mid=(a+b)>>1;
	ans=sum[abs(mid-a)]+sum[abs(mid-b)];
	cout<<ans<<endl;
	return 0;
}