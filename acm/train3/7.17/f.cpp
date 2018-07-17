#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e6+10;
LL cnt[maxn]={0};
int main(){
	LL t,n,i,j,ans;
	cin>>t;
	while(t--){
		scanf("%lld",&n);
		ans=0;
		for(i=0;i<n;i++){
			scanf("%lld",&j);
			cnt[j]++;
		}
		for(i=1;i<=1e6;i++){
			if(cnt[i]==0)continue;
			for(j=1;j*i<=1e6;j++){
				if(cnt[i*j]==0)continue;
				ans+=i*cnt[i*j];
				cnt[i*j]=0;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}