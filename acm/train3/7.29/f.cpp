#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	LL i,t,j;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		j=0;
		if(s[0]=='0'){
			cout<<0<<endl;
			continue;
		}
		if(s[0]=='-')j=1;
		if(j==0)cout<<"-"<<s<<endl;
		else{
			for(i=1;i<(LL)s.length();i++)cout<<s[i];
			cout<<endl;
		}
	}
	return 0;
}