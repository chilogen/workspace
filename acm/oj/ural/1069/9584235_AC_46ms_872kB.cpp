#include <bits/stdc++.h>
using namespace std;
#define reset(a,b)	memset(a,b,sizeof(a))
struct edge
{
	int u,v;
};
struct cmp{
	bool operator()(int a,int b){return a>b;}
};
edge e[15020];
int edge_num=0;
int first[15020],nex[15020];
void connect(int x,int y)
{
	e[edge_num].u=x;	e[edge_num].v=y;
	if(first[x]!=-1)	nex[edge_num]=first[x];
	first[x]=edge_num;
	edge_num++;
}
int main()
{
	priority_queue<int,vector<int>,cmp>	leaf;
	int deg[7501],a[7501],ans[7501],i,j,k,l;
	reset(deg,0);
	reset(first,-1);
	reset(nex,-1);
	i=0;
	while(scanf("%d",&a[++i])!=EOF){
		deg[a[i]]++;
	}
	for(j=1;j<=i;j++){
		if(deg[j]==0)	leaf.push(j);
	}
	for(j=1;j<i;j++)
	{
		k=leaf.top();
		connect(k,a[j]);		
		connect(a[j],k);
		leaf.pop();
		deg[a[j]]--;
		if(deg[a[j]]==0)	leaf.push(a[j]);
	}
	for(j=1;j<=i;j++)
	{
		k=0;
		ans[k++]=e[first[j]].v;
		l=nex[first[j]];
		while(l!=-1){
			ans[k++]=e[l].v;
			l=nex[l];
		}
		sort(ans,ans+k);
		printf("%d:",j);
		for(l=0;l<k;l++)	printf(" %d",ans[l]);
		puts("");
	}
	return 0;
}