#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL a[501][501],n,m,i,j,k,l;
	cin>>n>>m;
	char c;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			c=getchar();
			if(c=='\n'){j--;	continue;}
			a[i][j]=c-'0';
		}
	}
	queue<pair<LL,LL> >q;
	queue<LL>dst;
	q.push(make_pair(0,0));
	dst.push(0);
	pair<LL,LL> tmp;
	LL d[501][501];
	for(i=0;i<500;i++)
		for(j=0;j<=500;j++)
			d[i][j]=(LL)1e17;
	LL x,y,dis;
	while(!q.empty())
	{
		tmp=q.front();	dis=dst.front();
		q.pop();	dst.pop();
		i=tmp.first;	j=tmp.second;
		if(i-a[i][j]>=0)
		{
			x=i-a[i][j];	y=j;
			if(x==n-1&&y==m-1)
			{
				cout<<dis+1<<endl;
				return 0;
			}
			if(d[x][y]>dis+1)
			{
				q.push(make_pair(x,y));
				dst.push(dis+1);
				d[x][y]=dis+1;
			}
		}
		if(i+a[i][j]<n)
		{
			x=i+a[i][j];	y=j;
			if(x==n-1&&y==m-1)
			{
				cout<<dis+1<<endl;
				return 0;
			}
			if(d[x][y]>dis+1)
			{
				q.push(make_pair(x,y));
				dst.push(dis+1);
				d[x][y]=dis+1;
			}

		}
		if(j-a[i][j]>=0)
		{
			x=i;	y=j-a[i][j];
			if(x==n-1&&y==m-1)
			{
				cout<<dis+1<<endl;
				return 0;
			}
			if(d[x][y]>dis+1)
			{
				q.push(make_pair(x,y));
				dst.push(dis+1);
				d[x][y]=dis+1;
			}

		}
		if(j+a[i][j]<m)
		{
			x=i;	y=j+a[i][j];
			if(x==n-1&&y==m-1)
			{
				cout<<dis+1<<endl;
				return 0;
			}
			if(d[x][y]>dis+1)
			{
				q.push(make_pair(x,y));
				dst.push(dis+1);
				d[x][y]=dis+1;
			}
		}
	}
	puts("IMPOSSIBLE");
	return 0;
}