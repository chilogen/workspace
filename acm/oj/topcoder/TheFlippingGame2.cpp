#include <bits/stdc++.h>
using namespace std;
class  TheFlippingGame2{
public:
	int MinimumMoves(int a, int b, vector <string> x){
		vector<string>v;
		this->n=a;	this->m=b;
		return min(solve(get(x,'w'),'w'),solve(get(x,'b'),'b'));
	}
private:
	int a[30][30],ans,m,n;
	vector<string>v;
	int solve(vector<string> x,char c){
		int i,j;
		v=x;ans=0;
		memset(a,-1,sizeof(a));
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(x[i][j]!=c)continue;
				if(a[i][j]!=-1)continue;
				cs(i,j,c);
				ans++;
			}
		}
		return ans+1;
	}
	void cs(int x,int y,char c){
		int xx[]={1,-1,0,0},yy[]={0,0,-1,1};
		queue<pair<int,int> >q;
		pair<int,int>p;
		q.push(make_pair(x,y));a[x][y]=ans;
		while(!q.empty()){
			p=q.front();q.pop();
			x=p.first,y=p.second;
			for(int i=0;i<4;i++){
				p=make_pair(x+xx[i],y+yy[i]);
				if(p.first>=n||p.first<0)continue;
				if(p.second>=m||p.second<0)continue;
				if(v[p.first][p.second]!=c)continue;
				if(a[p.first][p.second]!=-1)continue;
				q.push(p);
				a[p.first][p.second]=ans;
			}
		}
	}
	vector<string> get(vector<string> x,char c){
		int i,j,k=x.size(),len;
		string s;
		vector<string>v;
		for(i=0;i<k;i++){
			s=x[i];
			len=s.length();
			for(j=0;j<len;j++){
				if(s[j]=='e')s[j]=c;
			}
			v.push_back(s);
		}
		return v;
	}
}a;
int main(){
	int i,j,k;
	string s;
	vector<string>v;
	cin>>i>>j;
	for(k=0;k<i;k++){
		cin>>s;
		v.push_back(s);
	}
	k=a.MinimumMoves(i,j,v);
	cout<<k<<endl;
	return 0;
}