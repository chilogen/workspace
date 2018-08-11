#include <bits/stdc++.h>
using namespace std;
char a[9][9];
bool check(int x,int y)
{
	int sx,ex,sy,ey;
	int i,j;
	sx=(x)*3,ex=sx+2;
	sy=(y)*3,ey=sy+2;
	for(i=sx;i<=ex;i++)
	{
		for(j=sy;j<=ey;j++)
		{
			if(a[i][j]=='.')	return 1;
		}
	}
	return 0;
}
void fill(int x,int y)
{
	int sx,ex,sy,ey;
	int i,j;
	sx=(x)*3,ex=sx+2;
	sy=(y)*3,ey=sy+2;
	for(i=sx;i<=ex;i++)
	{
		for(j=sy;j<=ey;j++)
		{
			if(a[i][j]=='.')	a[i][j]='!';
		}
	}
}
int main()
{
	char c;
	int i,j,k,l,n,m,x,y;
	for(i=0;i<9;i++)
	{
		if(i%3==0&&i!=0)	c=getchar();
		for(j=0;j<9;j++)
		{
			if(j%3==0&&j!=0)	c=getchar();
			cin>>a[i][j];
		}
	}
	cin>>x>>y;
	x--,y--;
	l=x/3,k=y/3;
	x-=3*l,y-=3*k;
	if(check(x,y))	fill(x,y);
	else
	{
		for(i=0;i<9;i++)
			for(j=0;j<9;j++)
			{
				if(a[i][j]=='.')
					a[i][j]='!';
			}
	}
	for(i=0;i<9;i++)
	{
		if(i%3==0&&i!=0)	cout<<endl;
		for(j=0;j<9;j++)
		{
			if(j%3==0&&j!=0)	cout<<" ";
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}