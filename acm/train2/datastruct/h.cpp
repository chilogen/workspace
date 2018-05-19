#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL t,n,i,j,ans;
	cin>>t;
	while(t--){
		priority_queue<LL,vector<LL>,greater<LL>>q;
		ans=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++){
			scanf("%lld",&j);
			q.push(j);
		}
		while(q.size()>=2){
			i=q.top();q.pop();
			j=q.top();q.pop();
			i=i+j;
			ans+=i;
			q.push(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}