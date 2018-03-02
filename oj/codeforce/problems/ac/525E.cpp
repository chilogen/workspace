#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,s,a[26],fact[21],ans=0;
map<LL,LL>m[26];
bool cmp(LL x,LL y){return x>y;}
void dfs1(LL x,LL y,LL sum){
	if(sum>s||(a[x]<=19&&sum+fact[a[x]]*(n-x+1)<s)||sum+fact[19]*(n-x+1)<s)	return ;
	if(x>(n+1)>>1){
		m[y][sum]++;
		return;
	}
	dfs1(x+1,y,sum);
	dfs1(x+1,y,sum+a[x]);
	if(a[x]<=19&&y<k)	dfs1(x+1,y+1,sum+fact[a[x]]);
}
void dfs2(LL x,LL y,LL sum){
	LL i,j;
	if(sum>s)	return;
	if(x>n){
		for(i=0;i<=k-y;i++)	
			ans+=m[i][s-sum];
		return;
	}
	dfs2(x+1,y,sum);
	dfs2(x+1,y,sum+a[x]);
	if(a[x]<=19&&y<k)	dfs2(x+1,y+1,sum+fact[a[x]]);
}
int main(){
	LL i,j;
	cin>>n>>k>>s;
	for(i=1;i<=n;i++)	cin>>a[i];
	for(i=1,fact[0]=1;i<=19;i++)	fact[i]=i*fact[i-1];
	sort(a+1,a+1+n,cmp);
	dfs1(1,0,0);
	dfs2(((n+1)>>1)+1,0,0);
	cout<<ans<<endl;
	return 0;
}