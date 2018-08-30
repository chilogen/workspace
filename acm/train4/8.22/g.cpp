#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s[510];

queue<pair<LL,LL> >dbfs;
void solve(){
	LL n,m,i,k,x,y;
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>s[i];
	for(i=0;i<m;i++){
		if(s[0][i]=='.'){
			s[0][i]='w';
			dbfs.push(make_pair(0,i));
		}
	}
	pair<LL,LL>tp;
	while(!dbfs.empty()){
		tp=dbfs.front();dbfs.pop();
		x=tp.first+1;y=tp.second;
		if(x<n&&s[x][y]=='.'){
			s[x][y]='w';
			dbfs.push(make_pair(x,y));
			continue;
		}
		x--;y--;
		if(y>=0&&s[x][y]=='.'){
			s[x][y]='w';
			dbfs.push(make_pair(x,y));
		}
		y+=2;
		if(y<m&&s[x][y]=='.'){
			s[x][y]='w';
			dbfs.push(make_pair(x,y));
		}
	}
	k=0;
	for(x=0;x<n&&k==0;x++)for(y=0;y<m&&k==0;y++)
		if(s[x][y]=='.'){
			s[x][y]='X';
			k=1;
		}
	if(k==0){
		cout<<"No\n";
		return;
	}
	cout<<"Yes\n";
	for(x=0;x<n;x++){
		for(y=0;y<m;y++){
			if(s[x][y]=='w')cout<<".";
			else cout<<s[x][y];
		}
		cout<<endl;
	}
}
int main(){
	solve();
	return 0;
}