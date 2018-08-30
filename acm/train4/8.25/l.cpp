#include <bits/stdc++.h>
using namespace std;

int ind[260];

string tonum(char c){
	string ans="";
	int x=ind[(int)c];
	while(x){
		if(x&1)ans+='1';
		else ans+='0';
		x>>=1;
	}
	while(ans.length()<4)ans+='0';
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	char c;
	for(c='0';c<='9';c++)ind[(int)c]=c-'0';
	for(c='a';c<='e';c++)ind[(int)c]=c-'a'+10;
	for(c='A';c<='E';c++)ind[(int)c]=c-'A'+10;
	string s;
	int i,l;
	while(cin>>s){
		l=s.length();
		for(i=0;i<l;i++)cout<<tonum(s[i])<<" ";
	}
}