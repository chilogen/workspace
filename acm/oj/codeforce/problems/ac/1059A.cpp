#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

pair<LL,LL>cus[100010];


void solve(){
	LL n,l,a,i,j,k;
	cin>>n>>l>>a;
	for(i=0;i<n;i++){
		cin>>cus[i].first>>cus[i].second;
		cus[i].second+=cus[i].first;
	}
	sort(cus,cus+n);
	cus[n]=make_pair(l,l);
	for(i=j=k=0;i<=n;i++){
		k+=(cus[i].first-j)/a;
		j=cus[i].second;
	}
	cout<<k<<endl;
}

int main(){
	solve();
	return 0;
}