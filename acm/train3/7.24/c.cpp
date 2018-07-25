#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL t,n,q,m,c;
LL ans[210][30],ta[30];
string s[210];
string noans="Let's go to the library!!";
map<string,LL>ma;
string check(){
	LL i,j,tans,cnt=0;
	for(i=1;i<=c;i++){
		for(j=0;j<q;j++){
			if(ans[i][j]!=ta[j])break;
		}
		if(j==q){
			tans=i;
			cnt++;
		}
	}
	if(cnt==1)return s[tans];
	return noans;
}
int main(){
	cin>>t;
	string ts;
	LL i,j,k;
	while(t--){
		ma.clear();
		memset(ans,0,sizeof(ans));
		cin>>n>>q;
		cin>>c;
		for(i=1;i<=c;i++){
			cin>>s[i];
			ma[s[i]]=i;
		}
		for(i=0;i<q;i++){
			cin>>m;
			for(j=0;j<m;j++){
				cin>>ts;
				k=ma[ts];
				ans[k][i]=1;
			}
		}
		for(i=1;i<=n;i++){
			for(j=0;j<q;j++)cin>>ta[j];
			cout<<check()<<endl;
		}
	}
	return 0;
}