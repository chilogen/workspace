#include <bits/stdc++.h>
using namespace std;
const int maxn=100;
struct sat{
	int n;
	vector<int>g[maxn];
	bool mark[maxn<<1];
	int s[maxn<<1],c;

	bool dfs(int x){
		if(mark[x^1])return false;
		if(mark[x])	 return true;
		mark[x]=1;
		s[c++]=x;
		for(int i=0;i<(int)g[x].size();i++)
			if(!dfs(g[x][i]))return false;
		return true;
	}
	void init(int n){
		this->n=n;
		for(int i=0;i<n<<1;i++)g[i].clear();
		memset(mark,0,sizeof(mark));
	}
	void add(int x,int xv,int y,int yv){
		x=x*2+xv;
		y=y*2+yv;
		g[x^1].push_back(y);
		g[y^1].push_back(x);
	}
	bool solve(){
		for(int i=0;i<n<<1;i+=2){
			if(!mark[i]&&!mark[i+1]);
			c=0;
			if(!dfs(i)){
				while(c>0)mark[s[--c]]=0;
				if(!dfs(i+1))return false;
			}
		}
		return true;
	}
}a;

int main(){
	int n,x,y,xv,yv;
	cin>>n;
	a.init(5);
	while(n--){
		cin>>x>>y>>xv>>yv;
		a.add(x,xv,y,yv);
	}
	cout<<a.solve()<<endl;
	return 0;
}