#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	int n,ans=0;
	bool c[26]={0};
	char a;
	cin>>n;
	while(n--){
		cin>>a;
		c[a-'A']=1;
	}
	for(n=0;n<26;n++){
		if(c[n])ans++;
	}
	if(ans==3)cout<<"Three"<<endl;
	else cout<<"Four"<<endl;
	return 0;
}