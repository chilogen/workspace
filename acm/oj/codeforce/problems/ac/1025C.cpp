#include <bits/stdc++.h>
using namespace std;
string s;
int a[100010];
int check(int x){
	string s1="",s2="";
	int i,j,l=s.length(),ans=0;
	for(i=0;i<x;i++)s1+=s[i];
	for(;i<l;i++)s2+=s[i];
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	s=s1+s2;
	j=1;
	for(i=1;i<l;i++){
		if(s[i]!=s[i-1])j++;
		else{
			ans=max(ans,j);
			j=1;
		}
	}
	return max(ans,j);
}
int main(){
	int i,l;
	cin>>s;
	l=s.length();
	if(s[0]==s[l-1]){
		cout<<check(0)<<endl;
		return 0;
	}
	for(i=1;i<l;i++){
		if(s[i]!=s[i-1])continue;
		cout<<check(i)<<endl;
		return 0;
	}
	cout<<check(0)<<endl;
	return 0;
}