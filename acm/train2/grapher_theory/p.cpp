#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1010;
LL n,m,ans=0;
char s[maxn][maxn];
void dfs(LL x,LL y){
	s[x][y]='.';
	LL a[]={1,-1,0,0,-1,-1,1,1},b[]={0,0,1,-1,-1,1,-1,1},i,j,k;
	for(i=0;i<8;i++){
		j=a[i]+x;k=b[i]+y;
		if(j<0||j>=n||k<0||k>=m)continue;
		if(s[j][k]=='.')continue;
		dfs(j,k);
	}
}
int main(){
	LL i,j;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>s[i];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(s[i][j]!='@')continue;
			ans++;
			dfs(i,j);
		}
	}
	cout<<ans<<endl;
	return 0;
}