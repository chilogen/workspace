#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s[2];
LL cnt1=0,cnt01=0,ans=0;
int main(){
	LL n,i;
	cin>>n>>s[0]>>s[1];
	for(i=0;i<n;i++){
		if(s[0][i]=='1')cnt1++;
		if(s[0][i]=='1'&&s[1][i]=='1')cnt01++;
	}
	cnt01=cnt1-cnt01;
	for(i=0;i<n;i++){
		if(s[0][i]=='1')continue;
		if(s[1][i]=='1')ans+=(cnt01);
		else ans+=cnt1;
	}
	cout<<ans<<endl;
	return 0;
}