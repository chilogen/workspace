#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[]={2,3,5,7},t,n;
LL p[4][31];
vector<LL>v;
void init(){
	LL i,j;
	for(i=0;i<4;i++){
		p[i][0]=1;
		for(j=1;j<31;j++)p[i][j]=p[i][j-1]*a[i];
	}
}
void dfs(LL x,LL ans){
	if(x==4){
		v.push_back(ans);
		return;
	}
	LL i,k;
	for(i=0;i<30;i++){
		k=ans*p[x][i];
		if(k>1e9)return;
		dfs(x+1,k);
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	init();
	dfs(0,1);
	sort(v.begin(),v.end());
	vector<LL>::iterator p;
	p=unique(v.begin(),v.end());
	v.resize(p-v.begin());
	cin>>t;
	while(t--){
		cin>>n;
		p=lower_bound(v.begin(),v.end(),n);
		cout<<*p<<endl;
	}
	return 0;
}