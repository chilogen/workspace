#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,base;
vector<LL>ans;
void solve(){
	LL i;
	base=0;
	ans.clear();
	for(i=k+1;;i+=(2*k+1)){
		ans.push_back(i);
		if(i+k>=n)break;
	}
	if(ans[ans.size()-1]>n)base=ans[ans.size()-1]-n;
	cout<<ans.size()<<endl;
	for(i=0;i<(LL)ans.size();i++)cout<<ans[i]-base<<" ";
	cout<<endl;
}
int main(){
	while(cin>>n>>k)solve();
	return 0;
}