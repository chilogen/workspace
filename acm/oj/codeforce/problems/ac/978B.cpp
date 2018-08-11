#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
int main(){
	string s;
	LL i,j,k,ans=0;
	cin>>n>>s;
	for(i=0;i<n;i++){
		if(s[i]!='x')continue;
		for(j=i,k=0;j<n;j++,k++){
			if(s[j]!='x')break;
		}
		i=j-1;
		if(k>2)ans+=(k-2);
	}
	cout<<ans<<endl;
	return 0;
}