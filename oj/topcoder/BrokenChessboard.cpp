#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
class BrokenChessboard{
private:
	LL ans[2],w,h;
	int vis[1000][1000],corlor[1000][1000];
	void getans(int k){
		queue<pair<int,int> >q;
		LL x,y;
		memset(vis,-1,sizeof(vis));
		vis[0][0]=k;
		q.push(make_pair(0,0));
		while(!q.empty()){
			x=q.front().first,y=q.front().second;q.pop();
			if(vis[x][y]!=corlor[x][y])ans[k]++;
			if(x+1<w&&vis[x+1][y]==-1){
				vis[x+1][y]=!vis[x][y];
				q.push(make_pair(x+1,y));
			}
			if(y+1<h&&vis[x][y+1]==-1){
				vis[x][y+1]=!vis[x][y];
				q.push(make_pair(x,y+1));
			}
		}
	}
public:
	BrokenChessboard(){ans[0]=ans[1]=0;}
	int minimumFixes(vector <string> board){
		LL i,j;
		w=board[0].length(),h=board.size();
		for(i=0;i<h;i++)for(j=0;j<w;j++){
			if(board[i][j]=='W')corlor[i][j]=0;
			else corlor[i][j]=1;
		}
		getans(0);getans(1);
		return min(ans[0],ans[1]);
	}
}a;
int main(){
	vector<string>v;
	string s;
	int i,j;
	cin>>j;
	for(i=0;i<j;i++){
		cin>>s;
		v.push_back(s);
	}
	cout<<a.minimumFixes(v)<<endl;
	return 0;
}