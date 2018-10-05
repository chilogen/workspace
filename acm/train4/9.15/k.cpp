#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=10010,MAXN=1e6,mod=1e9+7;
LL pack[maxn],v[maxn],c;
LL obj[MAXN],cnt;
inline void add(LL v,LL c){
	LL i;
	c=(2<<c)-1;
	for(i=1;i<c;i*=2)if(v*i<=10000)obj[cnt++]=v*i;
}
void solve(){
	memset(pack,0,sizeof(pack));
	cnt=0;
	pack[0]=1;
	LL n,q,i,j,k,l;
	cin>>n>>q;
	for(i=0;i<n;i++)cin>>v[i];
	for(i=0;i<n;i++){
		cin>>c;
		add(v[i],c);
	}
	l=cnt;
	for(i=0;i<l;i++){
		for(j=maxn-5,k=j-obj[i];j>=0&&k>=0;j--,k--){
			pack[j]+=pack[k];
			pack[j]%=mod;
		}
	}
	for(i=0;i<q;i++){
		//cin>>j;
		//cout<<pack[j]<<endl;
		scanf("%lld",&j);
		printf("%lld\n",pack[i]);
	}
}
int main(){
	LL t;
	//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	scanf("%lld",&t);
	//cin>>t;
	while(t--)solve();
	return 0;
}