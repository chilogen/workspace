#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL>v;
LL n,s,ans=0;
int main(){
	LL i,j;
	cin>>n>>s;
	for(i=0;i<n;i++){
		cin>>j;
		v.push_back(j);
	}
	sort(v.begin(),v.end());
	if(v[n/2]<s){
		for(i=n/2;i<n;i++){
			if(v[i]>=s)break;
			ans+=(s-v[i]);
		}
	}
	else if(v[n/2]>s){
		for(i=n/2;i>=0;i--){
			if(v[i]<=s)break;
			ans+=(v[i]-s);
		}
	}
	cout<<ans<<endl;
	return 0;

}