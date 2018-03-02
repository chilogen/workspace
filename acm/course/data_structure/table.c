//邻接表
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int u,v;
}Edge;
int *first,*next;
int nedge,npoint;
Edge *edge;
int main()
{
	int lop;
	scanf("%d%d",&npoint,&nedge);
	first=(int *)malloc(sizeof(int)*npoint); //first数组保存某个节点的第一条边，初始为-1，代表该点无边与其它点相连
	next=(int *)malloc(sizeof(int)*npoint);  //next数组保存下一条边的位置，-1为结束
	edge=(Edge *)malloc(sizeof(Edge)*nedge);
	memset(first,-1,npoint*sizeof(int));
	memset(next,-1,npoint*(sizeof(int)));

	for(lop=0;lop<nedge;lop++)
	{
		scanf("%d%d",&edge[lop].u,&edge[lop].v);
		if(first[edge[lop].u]!=-1)
		{
			next[lop]=first[edge[lop].u];
		}
		first[edge[lop].u]=lop;
	}//邻接表构建

	for(lop=0;lop<npoint;lop++)
	{
		if(first[lop]!=-1)
		{
			printf("Edge of %d:\n",lop+1);
			printf("%d->%d\n",edge[first[lop]].u+1,edge[first[lop]].v+1);
			int n=first[lop];
			while(next[n]!=-1)
			{
				printf("%d->%d\n",edge[next[n]].u+1,edge[next[n]].v+1);
				n=next[n];
			}
		}
	}//输出邻接表
	return 0;
}
