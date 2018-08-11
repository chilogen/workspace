#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,l,m;
vector<LL>v;
LL used[100010]={0};
int main(){
	LL i,j,ans,o,p,q;
	ios::sync_with_stdio(false);
	cin>>n>>k>>l;m=n*k;
	for(i=0;i<m;i++){
		cin>>j;
		v.push_back(j);
	}
	sort(v.begin(),v.end());
	for(i=0;i<m;i++)if(v[i]-v[0]>l)break;
	o=i-1;p=m-1;ans=0;
	for(i=0;i<n;i++){
		while(used[o]){
			o--;
			if(o<0){
				cout<<0<<endl;
				return 0;
			}
		}
		used[o]=1;
		for(q=0;q<k-1;q++){
			while(used[p]){
				p--;
				if(p<0){
					cout<<0<<endl;
					return 0;
				}
			}
			used[p]=1;
		}
		ans+=min(v[o],v[p]);
	}
	cout<<ans<<endl;
	return 0;
}