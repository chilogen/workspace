#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
ULL cnt[10]={0},n,m[10];
vector<ULL>ans;
void check(ULL v){
	ULL c[10]={0},i=0,j=v;
	while(v){
		i++;
		c[v%10]++;
		v/=10;
	}
	if(i!=n)return;
	for(i=0;i<10;i++)if(c[i]!=cnt[i])return;
	ans.push_back(j);
}
void dfs(LL d,ULL remain,ULL sum){
	ULL i;
	d++;
	if(remain==0){
		check(sum);
		return;
	}
	if(d==10)return;
	for(i=0;i<=remain;i++){
		cnt[d]=i;
		dfs(d,remain-i,sum+i*m[d]);
	}
	cnt[d]=0;
}
ULL mpow(ULL x,ULL y){
	if(x==0)return 0;
	ULL ans=1,i;
	for(i=0;i<y;i++)ans=ans*x;
	return ans;
}
int main(){
	int i;
	cin>>n;
	for(i=0;i<10;i++)m[i]=mpow(i,n);
	dfs(-1,n,0);
	if(ans.size()==0)cout<<-1<<endl;
	else{
		sort(ans.begin(),ans.end());
		for(i=0;i<(LL)ans.size();i++)cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}