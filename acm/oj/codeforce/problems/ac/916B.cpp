#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=5e4;
LL n,k,base=maxn;
LL cnt[maxn+100]={0};
int main(){
	LL i,j,l,c;
	cin>>n>>k;
	l=c=0;
	while(n){
		if(n&1){
			cnt[l+base]=1;
			c++;
		}
		l++;
		n>>=1;
	}
	if(c>k){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	while(c<k){
		while(cnt[l+base]==0)l--;
		if(c+cnt[l+base]>k)break;
		c+=cnt[l+base];
		cnt[l+base-1]+=2*cnt[l+base];
		cnt[l+base]=0;
	}
	if(c<k){
		for(i=0;i<base+l;i++){
			cnt[i+1]+=cnt[i]/2;
			cnt[i]%=2;
		}
		for(i=0;i<maxn+99;i++)if(cnt[i]!=0){
			while(c<k){
				c++;
				cnt[i--]--;
				cnt[i]+=2;
			}
			break;
		}
	}
	for(i=maxn+99;i>=0;i--)
		for(j=0;j<cnt[i];j++)cout<<i-base<<" ";
	return 0;
}