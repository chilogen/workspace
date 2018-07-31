#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7,maxn=1e5+10;
LL t,n,ans;
vector<LL>a,has;
LL b[maxn];
LL tree[maxn];
map<LL,LL>ma;
LL lowbit(LL x){return x&(-x);}
void add(LL x,LL y){
	LL i;
	for(i=x;i<=n;i+=lowbit(i)){
		tree[i]+=y;
		tree[i]%=mod;
	}
}
LL query(LL x){
	LL tans=0,i;
	for(i=x-1;i>0;i-=lowbit(i)){
		tans+=tree[i];
		tans%=mod;
	}
	return tans;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	LL i,j;
	cin>>t;
	while(t--){
		ma.clear();
		a.clear();
		memset(tree,0,sizeof(tree));
		ans=0;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>j;
			a.push_back(j);
		}
		has=a;
		sort(has.begin(),has.end());
		vector<LL>::iterator it=unique(has.begin(),has.end());
		has.resize(it-has.begin());
		for(i=0;i<(LL)has.size();i++){
			ma[has[i]]=i;
		}
		for(i=0,j=has.size();i<n;i++){
			b[i]=j-ma[a[i]];
		}
		for(i=n-1;i>=0;i--){
			j=query(b[i])+1;
			ans=(ans+j)%mod;
			add(b[i],j);
		}
		cout<<ans<<endl;
	}
	return 0;
}