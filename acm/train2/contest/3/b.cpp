#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
map<char,LL>m;
LL a[]={2,4,5,7,8,10,11,13},b[9];
LL check(string s){
	LL ans=0,l=s.length(),i,j;
	for(i=0;i<l;i++){
		if(s[i]=='B')s[i]='8';
		if(s[i]=='G')s[i]='C';
		if(s[i]=='I')s[i]='1';
		if(s[i]=='O'||s[i]=='Q')s[i]='0';
		if(s[i]=='S')s[i]='5';
		if(s[i]=='U'||s[i]=='Y')s[i]='V';
		if(s[i]=='Z')s[i]='2';
	}
	for(i=0;i<8;i++){
		j=m[s[i]];
		ans+=(j*a[i]);
	}
	j=m[s[8]];
	if(ans%27!=j)return -1;
	reverse(s.begin(),s.end());
	for(i=1,ans=0;i<9;i++){
		ans+=(m[s[i]]*b[i]);
	}
	return ans;
}
int main(){
	LL i,j,k,p;
	string s="0123456789ACDEFHJKLMNPRTVWX";
	for(i=0;i<(LL)s.length();i++)m[s[i]]=i;
	for(i=2,b[1]=1;i<9;i++)b[i]=b[i-1]*27;
	cin>>p;
	while(p--){
		cin>>k>>s;
		cout<<k<<" ";
		j=check(s);
		if(j==-1)cout<<"Invalid\n";
		else cout<<j<<endl;
	}
	return 0;
}