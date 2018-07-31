#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e6+10;
LL t,n;
string s[2][maxn];
vector<LL>ans;
map<string,LL>ma;
LL vis[maxn],us=0;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	LL i,k,l;
	cin>>t;
	while(t--){
		cin>>n;
		ma.clear();
		memset(vis,0,sizeof(vis));
		us=0;
		ans.clear();
		for(i=0;i<n;i++){
			cin>>s[0][i];
			ma[s[0][i]]=i;
		}
		for(i=0;i<n;i++)cin>>s[1][i];
		k=-1;
		for(i=0;i<n;i++){
			l=ma[s[0][i]];
			if(vis[l]){
				vis[l]=0;
				us--;
			}
			else{
				vis[l]=1;
				us++;
			}
			l=ma[s[1][i]];
			if(vis[l]){
				vis[l]=0;
				us--;
			}
			else{
				vis[l]=1;
				us++;
			}
			if(us==0){
				ans.push_back(i-k);
				k=i;
			}
		}
		if(n-1-k!=0)ans.push_back(n-1-k);
		k=ans.size();
		for(i=0;i<k-1;i++){
			cout<<ans[i]<<" ";
		}
		cout<<ans[i]<<endl;
	}
	return 0;
}