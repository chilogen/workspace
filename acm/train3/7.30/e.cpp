#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s,t;
LL len;
bool equ(){
	LL i;
	for(i=0;i<len;i++)if(s[i]!=t[i])return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	LL i,j;
	cin>>s>>t;
	len=s.length();
	if(equ()){
		cout<<"YES\n";
		return 0;
	}
	for(i=0;i<len;i++)if(s[i]!=t[i])break;
	for(j=len-1;j>=0;j--)if(s[j]!=t[j])break;
	reverse(s.begin()+i,s.begin()+j+1);
	if(equ())cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}