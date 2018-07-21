#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ans=0,vis[30]={0},n,len[10],a[20],dep;
string s[10];
LL ma[2000],ca[2000]={};
LL tonum(LL x){
	LL ans=0,i,j,k,l=1;
	for(i=len[x]-1;i>=0;i--){
		j=ma[(LL)s[x][i]];
		k=a[j];
		ans+=(l*k);
		l*=10;
	}
	return ans;
}
bool check(){
	LL i,j,k=0,l;
	for(i=0;i<n;i++){
		j=ma[(LL)s[i][0]];
		k=a[j];
		if(k==0)return false;
	}
	k=0;
	for(i=0;i<n-1;i++){
		l=tonum(i);
		k+=l;
	}
	j=tonum(i);
	return j==k;
}
void dfs(LL x){
	LL i;
	if(x==dep){
		if(check())
			ans++;
		return;
	}
	for(i=0;i<=9;i++){
		if(vis[i])continue;
		vis[i]=1;
		a[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	LL i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>s[i];
		ca[(LL)s[i][0]]=1;
		len[i]=s[i].length();
	}
	for(i=0;i<n;i++){
		for(j=0;j<len[i];j++)vis[s[i][j]-'A']=1;
	}
	for(i=0,k=0;i<26;i++){
		if(vis[i]){
			ma[i+'A']=k++;
		}
	}
	memset(vis,0,sizeof(vis));
	dep=k;
	dfs(0);
	cout<<ans<<endl;
	return 0;
}