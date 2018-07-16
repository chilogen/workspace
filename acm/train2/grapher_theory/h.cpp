#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=5e4+10;
struct decision{
	LL l,r,v;
	decision(LL a,LL b,LL c):l(a),r(b),v(c){}
};
vector<decision>d;
bool cmp(decision a,decision b){return a.r<b.r;}
LL dp[maxn],n,m;
int main(){
	LL i,j,k,l;
	cin>>m>>n;
	for(i=0;i<n;i++){
		cin>>j>>k>>l;
		d.push_back(decision(j,k,l));
	}
	sort(d.begin(),d.end(),cmp);
	memset(dp,0,sizeof(dp));
	for(i=j=0;i<n;i++){
		for(;j+1<=d[i].r;j++)dp[j+1]=dp[j];
		dp[j]=max(dp[j],max(dp[j-1],dp[d[i].l-1]+d[i].v));
		k=j;l=dp[j];
		while(k&&abs(dp[k]-dp[k-1])>=2){
			k--;l--;
			dp[k]=l;
		}
	}
	for(;j+1<maxn;j++)dp[j+1]=dp[j];
	cout<<dp[m]<<endl;
	return 0;
}