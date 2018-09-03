#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string a,b;
LL n,ans=0;
int main(){
	cin>>n>>a>>b;
	LL i;
	a+='0';b+='0';
	for(i=0;i<n;i++){
		if(a[i]==b[i])continue;
		if(a[i+1]!=b[i+1])swap(a[i],a[i+1]);
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}