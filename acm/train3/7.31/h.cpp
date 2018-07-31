#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL>ans;
LL n;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	LL i;
	while(n){
		if(n%2==0){
			ans.push_back(1);
			n=(n-2)/2;
		}
		else{
			ans.push_back(0);
			n=(n-1)/2;
		}
	}
	for(i=ans.size()-1;i>=0;i--){
		if(ans[i]==1)cout<<"B";
		else cout<<"A";
	}
	return 0;
}