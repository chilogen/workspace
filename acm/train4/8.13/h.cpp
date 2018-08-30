#include <bits/stdc++.h>
using namespace std;
int dp[2010][2010];
string s;
int n,m,k,size[2010],cnt,len;
int dfs(int x,int remain){
	int i;
	if(x==len)return-1;
	if(dp[x][remain]!=-1)return dp[x][remain];
	if(k*size[x]>=remain)return dp[x][remain]=1;
	for(i=size[x];i<=k*size[x];i++){
		if(remain-i<0)break;
		if(dfs(x+1,remain-i)==0)return dp[x][remain]=1;
	}
	return dp[x][remain]=0;
}
int main(){
	int t,i,j,l,kase=1;
	string ts;
	cin>>t;
	while(t--){
		memset(dp,-1,sizeof(dp));
		cout<<"Case #"<<kase++<<": ";
		cin>>n>>m>>k;
		cin>>ts;l=ts.length();
		cnt=0;s="";s+=ts[0];j=1;
		for(i=1;i<l;i++)
			if(ts[i]==ts[i-1])j++;
			else{
				size[cnt++]=j;
				j=1;
				s+=ts[i];
			}
		size[cnt]=j;len=s.length();
		if(dfs(0,m))cout<<s[0]<<endl;
		else cout<<(char)('A'+'B'-s[0])<<endl;
	}
	return 0;
}