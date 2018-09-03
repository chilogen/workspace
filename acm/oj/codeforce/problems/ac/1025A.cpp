#include<bits/stdc++.h>
using namespace std;
int cnt[26]={0};
int main(){
	int n,i,j,k;
	char c;
	cin>>n;
	if(n==1){
		cout<<"Yes\n";
		return 0;
	}
	while(n--){
		cin>>c;
		cnt[c-'a']++;
	}
	j=k=0;
	for(i=0;i<26;i++){
		if(cnt[i]!=0)j++;
		if(cnt[i]>1)k++;
	}
	if(j>0&&k==0)cout<<"No\n";
	else cout<<"Yes\n";
	return 0;
}