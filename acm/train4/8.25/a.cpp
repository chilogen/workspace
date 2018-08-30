#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

char tohex(LL x){
	if(x>=0&&x<=9)return x+'0';
	x-=10;
	return 'A'+x;
}
string s,ans;
void solve(){
	LL x;
	cin>>s;
	ans="";
	LL i,j,len=s.length();
	for(i=len-1;i>=0;i-=4){
		x=0;
		for(j=max(0ll,i-3);j<=i;j++){
			if(i-j<0)break;
			x<<=1;
			x+=(s[j]-'0');
		}
		ans+=tohex(x);
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
}

int main(){
	LL t;
	cin>>t;
	while(t--)solve();
	return 0;
}