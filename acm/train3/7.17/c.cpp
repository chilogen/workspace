#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s[2];
void tobit(int x,int y){
	s[y]="";
	while(x){
		if(x&1)s[y]+='1';
		else s[y]+='0';
		x>>=1;
	}
}
int main(){
	int t,n,i,k,ans;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		tobit(n,0);
		tobit(n-1,1);
		k=s[0].length();
		ans=0;
		while(s[1].length()<s[0].length())s[1]+='0';
		for(i=0;i<k;i++){
			if(s[0][i]!=s[1][i])ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}