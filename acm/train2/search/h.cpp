#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=200010;
const LL sigma=26;
LL nex[2][maxn][sigma]={0},fail[2][maxn]={0};
LL cnt[2][maxn]={0},len[2][maxn]={0},last,cur,now,n,p;
LL ans=0; 
char s[maxn];
void build(string str,LL ind){
	s[0]='A';
	n=0;p=2;last=0;
	fail[ind][0]=1;len[ind][1]=-1;
	LL i,j,k,l=str.length();
	for(i=0;i<l;i++){
		k=str[i]-'a';
		s[++n]=str[i];
		cur=last;
		while(s[n-len[ind][cur]-1]!=s[n])
			cur=fail[ind][cur];
		if(!nex[ind][cur][k]){
			now=p++;
			len[ind][now]=len[ind][cur]+2;
			j=fail[ind][cur];
			while(s[n-len[ind][j]-1]!=s[n])
				j=fail[ind][j];
			fail[ind][now]=nex[ind][j][k];
			nex[ind][cur][k]=now;
		}
		last=nex[ind][cur][k];
		cnt[ind][last]++;
	}
	for(i=p-1;i>=0;i--)cnt[ind][fail[ind][i]]+=cnt[ind][i];
}
void dfs(LL x,LL y){
	LL i,j,k;
	for(i=0;i<sigma;i++){
		j=nex[0][x][i];k=nex[1][y][i];
		if(j&&k){
			ans+=(cnt[1][k]*cnt[0][j]);
			dfs(j,k);
		}
	}
}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	build(s1,0);
	build(s2,1);
	dfs(0,0);
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}