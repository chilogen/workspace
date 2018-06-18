#include <bits/stdc++.h>
using namespace std;
const int maxn=100010;
int t,n,d[maxn];
string s;
int main(){
	int i,j;
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		cin>>s;
		d[0]=d[1]=0;
		for(i=1;i<n;i++){
			j=d[i];
			while(j&&s[i]!=s[j])j=d[j];
			if(s[i]==s[j])d[i+1]=j+1;
			else d[i+1]=0;
		}
		j=n-d[n];
		cout<<j<<endl;
		for(i=0;i<j;i++)cout<<s[i];
		cout<<endl;
	}
	return 0;
}