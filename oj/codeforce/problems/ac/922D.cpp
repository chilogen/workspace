#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,numh=0;
LL count(string s){
	LL len=s.length(),i,a=0;
	numh=0;
	for(i=0;i<len;i++){
		if(s[i]=='h')	numh++;
	}
	for(i=0;i<len;i++){
		if(s[i]=='s')	a+=numh;
		else numh--;
	}
	return a;
}
bool cmp(string a,string b){
	return count(a+b)>count(b+a);
}
int main(){
	string s,s1[100010];
	LL i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>s1[i];
	}
	sort(s1,s1+n,cmp);
	for(i=0;i<n;i++)s+=s1[i];
	cout<<count(s)<<endl;
	return 0;
}