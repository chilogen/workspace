#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,p,cnt[1010],c=0;
vector<LL>v[1010];
void connect(LL x,LL y){
	v[x].push_back(y);
	v[y].push_back(x);
}
bool dfs(LL x,LL from){
	c++;
	LL o;
	vector<LL>::iterator p=v[x].begin();
	while(p!=v[x].end()){
		o=*p;p++;;
		if(o==from)continue;
		if(o<=x)return false;
		dfs(o,x);
	}
	return true;
}
int main(){
	LL i;
	cin>>n;
	for(i=1;i<=n;i++)cin>>cnt[i];
	for(i=1,p=2;i<=n&&p<=n;i++){
		while(cnt[i]>0){
			cnt[i]--;
			while(p<=n&&cnt[p]<1)p++;
			if(p>n){
				cout<<"NO\n";
				return 0;
			}
			connect(i,p);
			cnt[p++]--;
		}
	}
	for(i=1;i<=n;i++){
		if(cnt[i]>0){
			cout<<"NO\n";
			return 0;
		}
	}
	if(!dfs(1,-1)||c<n)cout<<"NO\n";
	else cout<<"YES\n";
	return 0;
}