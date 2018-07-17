#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7,maxn=1e5+10;
LL a[maxn],front[maxn],back[maxn];
LL t,n,ans;
int main(){
	LL i,j,k;
	cin>>t;
	while(t--){
		scanf("%lld",&n);
		for(i=1,front[0]=a[0]=1;i<=n;i++){
			scanf("%lld",&a[i]);
			front[i]=front[i-1]*a[i-1];
			front[i]%=mod;
		}
		for(i=n,back[n+1]=a[n+1]=1;i>=1;i--){
			back[i]=back[i+1]*a[i+1];
			back[i]%=mod;
		}
		for(i=1,ans=0;i<=n;i++){
			j=a[i]-1;
			k=front[i]*j;
			k%=mod;
			k=k*back[i];
			k%=mod;
			ans+=k;
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}