#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL t,n,x,y;
string s[2];
string ans[]={"Not lying","Lying"};
int main(){
	LL i;
	cin>>t;
	while(t--){
		cin>>n>>x>>y>>s[0]>>s[1];
		for(i=0;i<n;i++){
			if(s[0][i]==s[1][i]){
				if(x>0&&y>0){x--;y--;}
			}
			else{
				if(x>y&&x>0)x--;
				else if(y>0)y--;
			}
		}
		if(x==0&&y==0)cout<<ans[0]<<endl;
		else cout<<ans[1]<<endl;
	}
	return 0;
}