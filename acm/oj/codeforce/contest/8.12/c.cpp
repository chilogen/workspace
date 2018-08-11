#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector <LL>	tree[200001];
LL n;
double ans=0;
void dfs(LL x,LL from,double pro)
{
	if(tree[x].size()==1&&from!=0)	return ;
	if(tree[x].size()==0)	return ;
	ans+=pro;
	for(auto i:tree[x])	
		if(i!=from&&from!=0)	dfs(i,x,pro/(tree[x].size()-1));
		else if(i!=from&&from==0)	dfs(i,x,pro/tree[x].size());
}
int main()
{
	LL i,j,k,u,v;
	cin>>n;
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&u,&v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(1,0,1);
	printf("%.10lf\n",ans);
	return 0;
}