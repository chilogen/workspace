#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Inf=1e11;
LL n,a[100010],cnt[3],c[3],ans,base=Inf,mn=Inf,mx=-Inf;
int main(){
	LL i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		base=min(base,a[i]);
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	for(i=0;i<n;i++){
		a[i]-=base;
		cnt[a[i]]++;
	}
	for(i=0;i<3;i++)c[i]=cnt[i];
	ans=0;
	if(mx-mn==2){
		ans=cnt[1]-cnt[1]%2;
		c[1]-=ans;
		c[0]+=(ans>>1);
		c[2]+=(ans>>1);

		j=min(cnt[0],cnt[2]);
		j=j<<1;
		
		if(j>ans){
			ans=j;
			c[1]=cnt[1]+j;
			c[0]=cnt[0]-(j>>1);
			c[2]=cnt[2]-(j>>1);
		}
	}
	cout<<n-ans<<endl;
	for(i=0;i<n;i++) for(j=0;j<3;j++){
		if(c[j]){
			cout<<j+base<<" ";
			c[j]--;
			break;
		}
	}
	cout<<endl;
	return 0;
}
