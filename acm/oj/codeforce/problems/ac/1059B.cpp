#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
LL dx[]={1,-1,0,0},dy[]={0,0,1,-1};
string s[1010];
string patten[]={"###","#.#","###"};

bool check(LL x,LL y){
	if(x<0||y<0||x+2>=n||y+2>=m)return false;
	LL i,j;
	for(i=x;i<x+3;i++){
		for(j=y;j<y+3;j++){
			if(i==x+1&&j==y+1)continue;
			if(s[i][j]!=patten[i-x][j-y])return false;
		}
	}
	return true;
}

bool atcorner(LL x,LL y){
	return check(x,y)||check(x-2,y)||check(x,y-2)||check(x-2,y-2);
}
bool atmiddle(LL x,LL y){
	return check(x,y-1)||check(x-1,y)||check(x-2,y-1)||check(x-1,y-2);
}
void dfs(LL x,LL y,LL& cnt){
	s[x][y]='?';
	if(cnt!=-1)cnt++;
	LL i,tx,ty;
	for(i=0;i<4;i++){
		tx=x+dx[i];
		ty=y+dy[i];
		if(tx<0||ty<0||tx>=n||ty>=m){
			cnt=-1;
			continue;
		}
		if(s[tx][ty]!='.')continue;
		dfs(tx,ty,cnt);
	}
}

bool solve(){
	LL i,j,k;
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>s[i];
	for(i=0;i<n;i++)for(j=0;j<m;j++){
		if(s[i][j]=='.'){
			k=0;
			dfs(i,j,k);
			if(k!=-1&&k!=1)
				return false;
		}
		else if(s[i][j]=='#'){
			if(!atcorner(i,j)&&!atmiddle(i,j))
				return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	if(solve())cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}