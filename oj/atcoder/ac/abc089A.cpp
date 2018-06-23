#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	int n,ans=0;
	cin>>n;
	while(n){
		if(n>=3){
			n-=3;
			ans++;
			continue;
		}
		break;
	}
	cout<<ans<<endl;
	return 0;
}