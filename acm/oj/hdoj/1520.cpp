//muti case!!!!!!!!

#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int dp[6010][2],v[6010],deg[6010]={0},n;
queue<int>bfs;
vector<int>edges[6010];
int fat[6010];
int main(){
	int i,j,k,l;
	while(cin>>n){
		memset(fat,-1,sizeof(fat));
		memset(deg,0,sizeof(deg));
		for(i=0;i<=n;i++)edges[i].clear();
		for(i=1;i<=n;i++)cin>>v[i];
		while(1){
			cin>>j>>k;
			if(j+k==0)break;
			edges[k].push_back(j);
			fat[j]=k;
			deg[k]++;
		}
		for(i=1;i<=n;i++)if(deg[i]==0)bfs.push(i);
		while(!bfs.empty()){
			i=bfs.front();bfs.pop();
			if(edges[i].size()==0){
				dp[i][0]=0;
				dp[i][1]=v[i];
				deg[fat[i]]--;
				if(deg[fat[i]]==0)bfs.push(fat[i]);
				continue;
			}
			else dp[i][0]=dp[i][1]=-inf;
			for(j=k=l=0;j<(int)edges[i].size();j++){
				k+=dp[edges[i][j]][0];
				l+=max(dp[edges[i][j]][0],dp[edges[i][j]][1]);
			}
			dp[i][0]=l;
			dp[i][1]=k+v[i];
			deg[fat[i]]--;
			if(deg[fat[i]]==0)bfs.push(fat[i]);
		}
		for(i=1;i<=n;i++)if(fat[i]==-1){
			cout<<max(dp[i][0],dp[i][1])<<endl;
			break;
		}
	}
	return 0;
}
