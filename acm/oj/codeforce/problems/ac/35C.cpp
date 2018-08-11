/*Because n and m just bewteen 1 and 2000,
*just use brute force,nothing to say
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,m,a[2010][2010];
LL ansd=-1,ansx,ansy;
pair<LL,LL>p[20];
int main()
{
	LL i,j,x,y;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=0;i<k;i++)	scanf("%lld%lld",&p[i].first,&p[i].second);
	for(x=1;x<=n;x++)
	{
		for(y=1;y<=m;y++)
		{
			a[x][y]=999999999;
			for(i=0;i<k;i++)
				a[x][y]=min(a[x][y],abs(x-p[i].first)+abs(y-p[i].second));
			if(a[x][y]>ansd)	ansd=a[x][y],ansx=x,ansy=y;
		}
	}
	printf("%lld %lld",ansx,ansy);
	return 0;
}