#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
	LL x,y,d,o;
};
struct cmp{
	bool operator()(node a,node b){return a.d>b.d;}
};
LL n,m,sx,sy,ex,ey;
LL dx[]={1,-1,0,0},dy[]={0,0,1,-1};
LL d[110][110][2];
char c[110][110];

bool floodfill(LL l){
	bool vis[110][110]={0};
	LL x,y,i;
	queue<pair<LL,LL> >bfs;
	bfs.push(make_pair(ex,ey));vis[ex][ey]=1;
	while(!bfs.empty()){
		pair<LL,LL>tp=bfs.front();bfs.pop();
		for(i=0;i<4;i++){
			x=tp.first+dx[i];
			y=tp.second+dy[i];
			if(x<1||x>n||y<1||y>n)continue;
			if(vis[x][y])continue;
			vis[x][y]=1;
			bfs.push(make_pair(x,y));
		}
	}
	if(!vis[x][y]&&l==0)return true;
	return false;
}

LL solve(){
	priority_queue<node,vector<node>,cmp>q;
	LL i,j,l=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>c[i][j];
			if(c[i][j]=='S'){
				sx=i;
				sy=j;
			}
			if(c[i][j]=='B')l=1;
			if(c[i][j]=='T'){
				ex=i;
				ey=j;
			}
		}
	}
	if(floodfill(l))return -1;
	q.push((node){sx,sy,0,0});
	while(1){
		node tn=q.top();q.pop();
		node tx;
		for(i=0;i<4;i++){
			tx.x=tn.x+dx[i];
			tx.y=tn.y+dy[i];
			if(tx.x<1||tx.y<1||tx.x>n||tx.y>m)continue;
			tx.d=tn.d+1;
			if(c[tx.x][tx.y]=='T')return tx.d;
			if(c[tx.x][tx.y]=='P')tx.d--;
			if(c[tx.x][tx.y]=='#'){
				if(tx.o==0)continue;
				tx.o--;
				tx.d++;
			}
			if(c[tx.x][tx.y]=='B')tx.o++;
			q.push(tx);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	while(1){
		cin>>n>>m;
		if(n+m==0)break;
		cout<<solve()<<endl;
	}
	return 0;
}