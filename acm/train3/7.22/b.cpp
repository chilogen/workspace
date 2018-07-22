#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL cnt[10]={0},a,b,k,ans=0,p[10];
void check(LL x){
	LL c[10]={0},i,l=0;
	x*=k;
	if(x<a||x>b)return;
	while(x>0){
		c[x%10]++;
		x/=10;
	}
	for(i=0;i<10;i++)l+=c[i];
	c[0]+=18-l;
	for(i=0;i<10;i++){
		if(c[i]!=cnt[i])return;
	}
	ans++;
}
void dfs(LL x,LL remain,LL now){
	if(x==10){check(now);return;}
	LL i;
	for(i=remain;i>=0;i--){
		cnt[x]=i;
		dfs(x+1,remain-i,now+i*p[x]);
	}
}
int main(){
	cin>>k>>a>>b;
	LL i;
	for(i=0;i<10;i++)p[i]=i*i;
	dfs(0,18,0);
	cout<<ans<<endl;
	return 0;
}