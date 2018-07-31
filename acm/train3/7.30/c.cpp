#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<pair<LL,LL> >seg;
LL n,done;
vector<LL>ans;
bool cmp(pair<LL,LL>a,pair<LL,LL>b){
	return a.second<b.second;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	LL i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j>>k;
		seg.push_back(make_pair(j,k));
	}
	sort(seg.begin(),seg.end(),cmp);
	for(i=0,done=0;i<n;i++){
		if(seg[i].first>done){
			ans.push_back(seg[i].second);
			done=seg[i].second;
		}
	}
	cout<<ans.size()<<endl;
	for(i=0;i<(LL)ans.size();i++)cout<<ans[i]<<" ";
	return 0;
}