#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e7+10;
bool vis[maxn]={0};
LL a[100010],ans[100010],cnt=0;

inline void add(LL x){
	LL i,k=sqrt(x+1);
	for(i=k;i)
}

void solve(){
	LL n,i;
	scanf("%lld",&n);
	for(i=0;i<n;i++)scanf("%lld",&a[i]);
	sort(a,a+n);
	for(i=n-1;i>=0;i--){
		if(!vis[a[i]]){
			ans[cnt++]=a[i];
			add(a[i]);
		}
	}
	for(i=cnt-1;i>=0;i--)printf("%lld ",ans[i]);
}

int main(){
	solve();
	return 0;
}