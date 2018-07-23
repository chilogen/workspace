#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e5+10;
struct node{
	LL ind,kil;
}a[maxn];
bool cmp(node x,node y){
	return x.kil<y.kil;
}
vector<pair<LL,LL> >ans;
LL n;
int main(){
	LL i,j;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i].kil;
		a[i].ind=i+1;
	}
	sort(a,a+n,cmp);
	if(a[0].kil!=0){
		cout<<"NO\n";
		return 0;
	}
	i=0;
	for(j=1;j<n;j++){
		while(a[j].kil!=0){
			if(i>=j){
				cout<<"NO\n";
				return 0;
			}
			ans.push_back(make_pair(a[j].ind,a[i].ind));
			i++;
			a[j].kil--;
		}
	}
	for(i=0;i<n;i++)if(a[i].kil!=0){cout<<"NO\n";return 0;}
	cout<<"YES\n";
	for(i=0;i<(LL)ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<endl;
	return 0;
}