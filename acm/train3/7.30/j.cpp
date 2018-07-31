#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL  n,cnt[200010]={0},ans=0;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	LL i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j;
		cnt[j]++;
	}
	for(i=1,j=0;i<200010;i++){
		cnt[i]+=j;
		k=cnt[i]/4;
		ans+=k;
		cnt[i]-=(4*k);
		j=(cnt[i]/2)*2;
	}
	cout<<ans<<endl;
	return 0;
}