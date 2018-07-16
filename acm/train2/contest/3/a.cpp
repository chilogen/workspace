#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL o[15],x[15],d[15];
LL to(string s){
	LL i,j,l=s.length();
	LL ans=0;
	for(i=0;i<l;i++){
		j=s[i]-'0';
		if(j>=8)return 0;
		ans+=(j*o[i]);
	}
	return ans;
}
LL tx(string s){
	LL i,j,l=s.length();
	LL ans=0;
	for(i=0;i<l;i++){
		j=s[i]-'0';
		ans+=(j*x[i]);
	}
	return ans;
}
LL td(string s){
	LL i,j,l=s.length();
	LL ans=0;
	for(i=0;i<l;i++){
		j=s[i]-'0';
		ans+=(j*d[i]);
	}
	return ans;
}
int main(){
	LL i,k,n;
	o[0]=x[0]=d[0]=1;
	for(i=1;i<15;i++){
		o[i]=o[i-1]*8;
		x[i]=x[i-1]*16;
		d[i]=d[i-1]*10;
	}
	string s;
	cin>>n;
	while(n--){
		cin>>k>>s;
		reverse(s.begin(),s.end());
		cout<<k<<" "<<to(s)<<" "<<td(s)<<" "<<tx(s)<<endl;
	}
	return 0;
}