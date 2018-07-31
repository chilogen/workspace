#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=200010;
string s[maxn];
bool flag=false;
pair<LL,LL>st,en;
LL n,m,d;
LL dx[]={1,-1,0,0},dy[]={0,0,1,-1};
//ac
void ff(LL tx,LL ty){
	LL x,y,k,l1,l2,r1,r2;
	l1=max((LL)0,tx-d);l2=min(n-1,tx+d);
	for(x=l1;x<=l2;x++){
		k=d-abs(x-tx);
		r1=max((LL)0,ty-k);r2=min(m-1,ty+k);
		for(y=r1;y<=r2;y++){
			if(s[x][y]=='S'||s[x][y]=='F')flag=true;
			if(s[x][y]!='.')continue;
			s[x][y]='-';
		}
	}
}

//wa 44

void fff(LL tx,LL ty){
	queue<pair<LL,LL>>bfs;
	queue<LL>dist;
	bfs.push(make_pair(tx,ty));dist.push(0);
	pair<LL,LL>tp;
	LL i,k,x,y;
	while(!bfs.empty()&&!flag){
		tp=bfs.front();bfs.pop();
		k=dist.front();dist.pop();
		if(k>=d)continue;
		for(i=0;i<4;i++){
			x=tp.first+dx[i];
			y=tp.second+dy[i];
			if(x<0||y<0||x>=n||y>=m)continue;
			if(s[x][y]=='S'||s[x][y]=='F')flag=true;
			if(s[x][y]!='.')continue;
			s[x][y]='-';
			bfs.push(make_pair(x,y));
			dist.push(k+1);
		}
	}
}

queue<pair<LL,LL>>Bfs;
queue<LL>Dist;


//ac
void ffff(){
	pair<LL,LL>tp;
	LL i,k,x,y;
	while(!Bfs.empty()&&!flag){
		tp=Bfs.front();Bfs.pop();
		k=Dist.front();Dist.pop();
		if(k>=d)continue;
		for(i=0;i<4;i++){
			x=tp.first+dx[i];
			y=tp.second+dy[i];
			if(x<0||y<0||x>=n||y>=m)continue;
			if(s[x][y]=='S'||s[x][y]=='F')flag=true;
			if(s[x][y]!='.')continue;
			s[x][y]='-';
			Bfs.push(make_pair(x,y));
			Dist.push(k+1);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	LL i,j,k;
	LL x,y;
	pair<LL,LL>tp;
	cin>>n>>m>>d;
	for(i=0;i<n;i++)cin>>s[i];
	for(i=0;i<n&&!flag;i++){
		for(j=0;j<m&&!flag;j++){
			if(s[i][j]=='S')st=make_pair(i,j);
			if(s[i][j]=='F')en=make_pair(i,j);
		

		/******************************************/	

			if(s[i][j]=='M'){
				Bfs.push(make_pair(i,j));
				Dist.push(0);
			}
			//if(s[i][j]=='M')fff(i,j);
			//if(s[i][j]=='M')ff(i,j);


		/******************************************/
		

		}
	}
	ffff();
	if(flag){
		cout<<"-1"<<endl;
		return 0;
	}
	queue<pair<LL,LL>>bfs;
	queue<LL>dist;
	bfs.push(st);dist.push(0);
	while(!bfs.empty()){
		tp=bfs.front();bfs.pop();
		k=dist.front();dist.pop();
		for(i=0;i<4;i++){
			x=tp.first+dx[i];
			y=tp.second+dy[i];
			if(x<0||y<0||x>=n||y>=m)continue;
			if(s[x][y]=='F'){
				cout<<k+1<<endl;
				return 0;
			}
			if(s[x][y]=='.'){
				bfs.push(make_pair(x,y));
				dist.push(k+1);
				s[x][y]='*';
			}
		}
	}
	cout<<"-1"<<endl;
	return 0;
}