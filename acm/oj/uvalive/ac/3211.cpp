#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=4100;
struct sat2{
	int c,s[maxn],n;
	bool mark[maxn];
	vector<int>g[maxn];
	void init(int x){
		int i;
		n=x;c=0;
		memset(mark,0,sizeof(mark));
		for(i=0;i<=2*n;i++)g[i].clear();
	}
	bool dfs(int x){
		if(mark[x^1])return false;
		if(mark[x])return true;
		mark[x]=1;
		s[++c]=x;
		int i,j=g[x].size();
		for(i=0;i<j;i++)
			if(!dfs(g[x][i]))return false;
		return true;
	}

	//xv, yv is the value make (X | Y == TRUE)
	//for example: if you want x' | y to be true
	//the xv = 0, yv=1
	void add_clause(int x,int xv,int y,int yv){
		x=x*2+xv;
		y=y*2+yv;
		g[x^1].push_back(y);
		g[y^1].push_back(x);
	}

	bool solve(){
		int i;
		for(i=0;i<2*n;i+=2){
			if(mark[i]||mark[i^1])continue;
			c=0;
			if(dfs(i))continue;
			while(c>0)mark[s[c--]]=0;
			if(dfs(i+1))continue;
			return false;
		}
		return true;
	}
}solver2;

struct sat3{

}solver3;

int t[2100][2],n;

bool check(int x){
	int i,j,a,b;
	solver2.init(2000);
	for(i=0;i<n;i++)for(j=i+1;j<n;j++){
		for(a=0;a<2;a++)for(b=0;b<2;b++){

			//i-a = true or j-b =true
			if(abs(t[i][a]-t[j][b])<x)
				solver2.add_clause(i,a^1,j,b^1);
		}
	}
	return solver2.solve();
}
int main(){
	int i,l,r,mid;
	while(cin>>n){
		for(i=0;i<n;i++)cin>>t[i][0]>>t[i][1];
		l=0;r=1e7;
		while(l<r){
			mid=(l+r+1)>>1;
			if(check(mid))l=mid;
			else r=mid-1;
		}
		cout<<l<<endl;
	}
	return 0;
}
