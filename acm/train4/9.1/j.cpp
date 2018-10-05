#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e7+10;
const double Max=sqrt((double)maxn);
bool vis[maxn];
LL ss[maxn],cnt=0;
LL n,ans;

void init(){
	double i,j,k;
	for(i=2;i<=Max;i++){
		k=j=i*i;
		while(j<maxn){
			vis[(LL)j]=1;
			j+=k;
		}
	}
	for(i=1;i<=maxn;i++)if(!vis[(LL)i]){
		ss[cnt++]=i;
	}
}

void solve(){
	cin>>n;
	ans=0;
	LL l=0,r=cnt-1;;
	while(l<=r){
		if(ss[l]*ss[r]<=n){
			ans+=(2*(r-l)+1);
			l++;
		}
		else r--;
	}
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	init();
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}