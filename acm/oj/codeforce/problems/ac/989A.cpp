#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[110];
int main(){
	string str;
	cin>>str;
	LL i,j,l=str.length();
	for(i=0,j=1;i<l;i++,j++){
		if(str[i]=='.')a[j]=0;
		if(str[i]=='A')a[j]=1;
		if(str[i]=='B')a[j]=2;
		if(str[i]=='C')a[j]=4;
	}
	for(i=1;i<=l;i++){
		j=a[i-1]+a[i]+a[i+1];
		if(j==7){
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";
	return 0;
}