#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL cntlink=0,cntpear=0;
	string s;
	cin>>s;
	LL i,len=s.length();
	for(i=0;i<=len;i++){
		if(s[i]=='o')cntpear++;
	}
	cntlink=len-cntpear;
	if(cntpear==0){
		cout<<"YES\n";
		return 0;
	}
	if(cntlink%cntpear==0)cout<<"YES\n";
	else cout<<"NO"<<endl;
	return 0;
}