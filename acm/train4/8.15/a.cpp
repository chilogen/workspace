#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL NOans=1e16;
LL n,a[1010];
vector<LL>ans;
LL tonum(string s){
	if(s[0]=='x')return NOans;
	LL i,j=s.length(),k=0,l=1,m=0;
	if(s[0]=='-'){
		l=-1;
		m=1;
	}
	for(i=m;i<j;i++){
		k*=10;
		k+=(s[i]-'0');
	}
	return k*l;
}
bool check(){
	LL i,j,k;
	for(i=0;i<n-1;i++){
		if(a[i]==NOans)continue;
		j=i-1;k=i+1;
		if(i%2==0){
			if(j>=0&&a[j]!=NOans&&a[i]>=a[j])return false;
			if(k<n&&a[k]!=NOans&&a[i]>=a[k])return false;
		}
		else{
			if(j>=0&&a[j]!=NOans&&a[i]<=a[j])return false;
			if(k<n&&a[k]!=NOans&&a[i]<=a[k])return false;
		}
	}
	for(i=0;i<n-1;i++){
		if(a[i]!=NOans)continue;
		if(a[i+1]==NOans)return false;
	}
	return true;
}
int main(){
	cin>>n;
	string s;
	LL i,j,k,l=-1e15,r=1e15;
	for(i=0,k=0;i<n;i++){
		cin>>s;
		a[i]=tonum(s);
		if(a[i]==NOans)k++;
	}
	if(!check()||k==n){
		cout<<"none\n";
		return 0;
	}
	for(i=0;i<n;i++){
		if(a[i]!=NOans)continue;
		j=i-1;k=i+1;
		if(i%2==0){
			if(j>=0&&a[j]!=NOans)r=min(r,a[j]-1);
			if(k<n&&a[k]!=NOans)r=min(r,a[k]-1);
		}
		else{
			if(j>=0&&a[j]!=NOans)l=max(l,a[j]+1);
			if(k<n&&a[k]!=NOans)l=max(l,a[k]+1);
		}
	}
	if(l==r)cout<<l<<endl;
	else if(l>r)cout<<"none\n";
	else cout<<"ambiguous\n";
	return 0;
}