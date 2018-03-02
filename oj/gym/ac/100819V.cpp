#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int direction[1001];
struct gare
{
	LL x,y,r;
}g[1001];
inline LL dist(gare a,gare b)
{return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
int main()
{
	LL n,i,j;
	queue<LL>q;
	bool wrong=false;
	memset(direction,-1,sizeof(direction));
	cin>>n;
	for(i=1;i<=n;i++)	cin>>g[i].x>>g[i].y>>g[i].r;
	direction[1]=0;
	q.push(1);
	while(!q.empty()&&!wrong)
	{
		j=q.front();	q.pop();
		for(i=1;i<=n;i++)
		{
			if(dist(g[i],g[j])==(g[i].r+g[j].r)*(g[i].r+g[j].r))
			{
				if(direction[i]==-1)	{direction[i]=!direction[j];	q.push(i);}
				else if(direction[i]==direction[j])	
				{
					wrong=true;
					break;
				}
			}
		}
	}
	if(wrong)	puts("The input gear cannot move.");
	else if(direction[n]==-1)	puts("The input gear is not connected to the output gear.");
	else
	{
		if(direction[1]==!direction[n])	cout<<"-";
		cout<<g[1].r/__gcd(g[1].r,g[n].r)<<":"<<g[n].r/__gcd(g[1].r,g[n].r)<<endl;
	}
	return 0;
}