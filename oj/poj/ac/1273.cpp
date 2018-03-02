/*this is a classical training of max-flow problem.
*the main idea to find argmenting paths(use bfs or dfs)
*once find an argumenting path,rise the flow throught this
*path.and the find anohter one,until termnial point are not
*conntected to the source point.
*
*there are something need to notice:the input may contain
*same edge,so line 28 use '+=',or you will get a wrong anwser
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef long long LL;
LL n,m,p[210][210],from[210],vol[210],vis[201],inf=1e10,ans;
int main()
{
	LL i,j,k,x,y,v;
	while(scanf("%lld%lld",&m,&n)!=EOF)
	{
		memset(p,0,sizeof(p));
		ans=0;
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&v);
			p[x][y]+=v;
		}
		while(1)
		{
			queue<LL> bfs;
			memset(from,-1,sizeof(from));
			memset(vol,0,sizeof(vol));
			memset(vis,0,sizeof(vis));
			vol[1]=inf,vis[1]=1;;
			bfs.push(1);
			while(!bfs.empty())
			{
				k=bfs.front(),bfs.pop();
				if(p[k][n])
				{
					j=min(p[k][n],vol[k]);
					ans+=j;
					from[n]=k;
					break;
				}
				for(i=2;i<n;i++)
				{
					if(!p[k][i]||from[i]==k||vis[i])	continue;
					vol[i]+=min(p[k][i],vol[k]);
					from[i]=k;
					bfs.push(i),vis[i]=1;
				}
			}
			i=from[n];
			if(i==-1)	break;
			i=n;
			while(from[i]!=-1)
			{
				k=from[i];
				p[k][i]-=j;
				p[i][k]+=j;
				i=k;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}