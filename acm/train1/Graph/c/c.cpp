#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
	int sn;
};
struct cmpc
{
	bool operator()(const node &a,const node &b)
	{
		if(a.x!=b.x)	return a.x>b.x;
		else return a.y>b.y;
	}
};
struct cmpv
{
	bool operator()(const node &a,const node &b)
	{
		if(a.y!=b.y)	return a.y>b.y;
		else return a.x>b.x;
	}
};
short int color[200001];
int fro[200001],nex[200001];
priority_queue <node,vector<node>,cmpc> colume;
priority_queue <node,vector<node>,cmpv> volume;
queue <int> q;
void dyenex(int i,int col)
{
	void dyefro(int i,int col);
	if(nex[i]==-1)	return;
	i=nex[i];
	if(color[i]!=-1)	return;
	color[i]=col;
	dyenex(i,!col);
	dyefro(i,!col);
}
void dyefro(int i,int col)
{
	if(fro[i]==-1)	return ;
	i=fro[i];
	if(color[i]!=-1)	return;
	color[i]=col;
	dyefro(i,!col);
	dyenex(i,!col);
}
int main()
{
	//freopen("abc","r",stdin);
	int n,i,j,k,l;
	scanf("%d",&n);
	memset(color,-1,sizeof(color));
	memset(fro,-1,sizeof(fro));
	memset(nex,-1,sizeof(nex));
	node a1,a2;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a1.x,&a1.y);
		a1.sn=i;
		colume.push(a1);
		volume.push(a1);
	}
	while(colume.size()>=2)
	{
		a1=colume.top();
		colume.pop();
		a2=colume.top();
		if(a1.x!=a2.x)	continue;
		colume.pop();
		if(fro[a2.sn]==-1)	fro[a2.sn]=a1.sn;
		else nex[a2.sn]=a1.sn;
		if(nex[a1.sn]==-1)	nex[a1.sn]=a2.sn;
		else fro[a1.sn]=a2.sn;
	}
	while(volume.size()>=2)
	{
		a1=volume.top();
		volume.pop();
		a2=volume.top();
		if(a1.y!=a2.y)	continue;
		volume.pop();
		if(fro[a2.sn]==-1)	fro[a2.sn]=a1.sn;
		else nex[a2.sn]=a1.sn;
		if(nex[a1.sn]==-1)	nex[a1.sn]=a2.sn;
		else fro[a1.sn]=a2.sn;
	}
	for(i=1;i<=n;i++)
	{
		if(color[i]==-1)
		{
			color[i]=1;
			dyenex(i,0);
			dyefro(i,0);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(color[i]==1)	printf("b");
		else printf("r");
	}
	//fclose(stdin);
	return 0;
}
