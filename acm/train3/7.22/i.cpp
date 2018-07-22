#include <bits/stdc++.h>
using namespace std;
const int maxn=40;
double e[maxn][maxn],dst[maxn];
map<string,int>ma;
vector<int>to[maxn];
int n,m;
int main(){
	int i,j,k,kase=1;
	string a,b;
	bool found;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		cout<<"Case "<<kase++<<": ";
		found=false;
		ma.clear();
		memset(e,0,sizeof(e));
		memset(dst,0,sizeof(dst));
		for(i=0;i<=n;i++)to[i].clear();
		for(i=1;i<=n;i++){
			cin>>a;
			ma[a]=i;
		}
		scanf("%d",&m);
		for(i=0;i<m;i++){
			double r;
			cin>>a>>r>>b;
			j=ma[a];k=ma[b];
			e[j][k]=r;
			to[j].push_back(k);
		}
		queue<int>bfs;
		bfs.push(1);dst[1]=1000;
		while(!bfs.empty()){
			i=bfs.front();bfs.pop();
			if(i==1)found=(dst[i]>1000);
			j=to[i].size();
			if(found)break;
			for(k=0;k<j;k++){
				if(dst[to[i][k]]<dst[i]*e[i][to[i][k]]){
					dst[to[i][k]]=dst[i]*e[i][to[i][k]];
					bfs.push(to[i][k]);
				}
			}
		}
		cout<<(found?"Yes\n":"No\n");
	}
}