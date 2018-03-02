#include <bits/stdc++.h>
using namespace std;
queue <pair<int,int> >q;
char a[110][110];
int w,h;
int vis[110][110];
bool output;
int main()
{
	int n,i,j,k,l,e,x,y;
	cin>>n;
	while(n--)
	{
		cin>>w>>h;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				scanf("%c",&a[i][j]);
				if(a[i][j]=='\n')	{j--;	continue;}
				if(a[i][j]=='D')	output=true;
			}
		}
		cin>>e;
		for(k=0;k<e;k++)
		{
			cin>>x>>y;
			if(a[y][x]=='X')	continue;
			if(a[y][x]<'D')
			{
				a[y][x]++;
				if(a[y][x]=='D')	output=true;
				continue;
			}
			else if(a[y][x]=='D')
			{
				memset(vis,0,sizeof(vis));
				if(y-1>=0)	q.push(make_pair(y-1,x));
				if(y+1<h)	q.push(make_pair(y+1,x));
				if(x+1<w)	q.push(make_pair(y,x+1));
				if(x-1>=0)	q.push(make_pair(y,x-1));
				vis[y][x]=1;
				while(!q.empty())
				{
					y=q.front().first;	x=q.front().second;	q.pop();
					if(a[y][x]=='X')	continue;
					if(a[y][x]<'D')
					{
						a[y][x]++;
						if(a[y][x]=='D')	output=true;
						continue;
					}
					else if(a[y][x]=='D'&&vis[y][x]==0)
					{
						vis[y][x]=1;
						output=true;
						if(y-1>=0)	q.push(make_pair(y-1,x));
						if(y+1<h)	q.push(make_pair(y+1,x));
						if(x+1<w)	q.push(make_pair(y,x+1));
						if(x-1>=0)	q.push(make_pair(y,x-1));
					}
				}
			}
		}
		if(output)
		{
			for(i=0;i<h;i++)
			{
				for(j=0;j<w;j++)
				{
					cout<<a[i][j];
				}
				cout<<endl;
			}
		}
	}
	return 0;
}