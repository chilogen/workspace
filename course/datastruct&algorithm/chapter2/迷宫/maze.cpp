#include "maze.h"
#include <bits/stdc++.h>
using namespace std;

#define reset(a,b)	memset(a,b,sizeof(a))
typedef pair<int,int>	pii;

int nx[]={-1,1,0,0},ny[]={0,0,-1,1};
int mx[]={-2,2,0,0},my[]={0,0,-2,2};
int h,w;

maze::maze(int r,int c,pii src,pii dst)
{
	int i,j;
	srand((unsigned)time(NULL));
	row=r*2+1,col=c*2+1;
	heigth=r,width=c;
	s=src;	e=dst;
	m=new int *[row];
	for(i=0;i<row;i++)
	{
		m[i]=new int[col];
		for(j=0;j<col;j++)	m[i][j]=-1;
	}
	for(i=0;i<row;)
	{
		for(j=0;j<col;j++)	m[i][j]=1;
		i+=2;
	}
	for(j=0;j<col;)
	{
		for(i=0;i<row;i++)	m[i][j]=1;
		j+=2;
	}
}

bool dfs(int **p,int x,int y)
{
	int i,xx,yy,a[4]={0,1,2,3};
	if(x<=0||y<=0||x>=h||y>=w)	return false;
	if(p[x][y]==0)	return false;
	p[x][y]=0;
	for(i=0;i<4;i++)	swap(a[i],a[rand()%4]);
	for(i=0;i<4;i++)
	{
		xx=x+mx[a[i]];	yy=y+my[a[i]];
		if(dfs(p,xx,yy))	p[x+nx[a[i]]][y+ny[a[i]]]=0;
	}
	return true;
}

void maze::GenerateMap1()
{
	int i,x,y;
	x=(rand()%heigth)*2+1;
	y=(rand()%width)*2+1;
	h=this->row;
	w=this->col;
	dfs(this->m,x,y);
}

void maze::GenerateMap2()
{}

vector<pii>GetPath()
{}

vector<pii>GetShorestPath()
{}

ostream &operator <<(ostream &out,Maze &a)
{
	int i,j,k;
	for(i=0;i<a.row;i++)
	{
		for(j=0;j<a.col;j++)
			out<<a.m[i][j];
		out<<endl;
	}
}