/* 每个节点保存三个最大距离 maxd[3];
*  maxd[0]指该节点到其子树最远节点的距离，maxd[1]表示到子树的次远距离，maxd[2]表示经过其父节点的最远距离
*  son[2]分别保存最远距离和次远距离对应的子节点编号
*  maxd[0],maxd[1],son[0],son[1]通过第一遍dfs求得，第二遍dfs求maxd[2]和最终的答案
*  转移关系：每个节点的最终答案为 max(通过父亲节点到达的最远距离，其子树的最远距离maxd[0])
*	   通过父亲节点到达的最远距离为 max(通过父亲的父亲到达的最远距离，不经过该节点的最远子树距离（maxd[0]或maxd[1]）)
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int maxd[maxn][3],son[maxn][2],ans[maxn];
vector<int>g[maxn],v[maxn];
int n;
int dfs1(int x){
	int j,k;
	for(j=0;j<(int)g[x].size();j++){
		k=dfs1(g[x][j])+v[x][j];
		if(k>maxd[x][1]){
			maxd[x][1]=k;
			son[x][1]=g[x][j];
		}
		if(maxd[x][1]>maxd[x][0]){
			swap(maxd[x][1],maxd[x][0]);
			swap(son[x][1],son[x][0]);
		}
	}
	return maxd[x][0];
}
void dfs2(int x){
	int j,k;
	for(j=0;j<(int)g[x].size();j++){
		if(g[x][j]==son[x][0])k=maxd[x][1];
		else k=maxd[x][0];
		maxd[g[x][j]][2]=max(maxd[x][2]+v[x][j],k+v[x][j]);
		ans[g[x][j]]=max(maxd[g[x][j]][2],maxd[g[x][j]][0]);
		dfs2(g[x][j]);
	}
}
int main(){
	int i,j,k;
	while(cin>>n){
		for(i=0;i<=n;i++){
			g[i].clear();v[i].clear();
			maxd[i][0]=maxd[i][1]=maxd[i][2]=0;
		}
		for(i=2;i<=n;i++){
			cin>>j>>k;
			g[j].push_back(i);
			v[j].push_back(k);
		}
		dfs1(1);
		dfs2(1);
		ans[1]=maxd[1][0];
		for(i=1;i<=n;i++)cout<<ans[i]<<endl;
	}
	return 0;
}
