/*每一个存储l,r,bot
 * 代表[i,j]-[bot,j]这一列向左向右分别能移动多少列
 * 则答案等于向左向右移动列数之和与列长度（i-bot+1）的乘积
 * 蓝书P50
 */
#include <bits/stdc++.h>
using namespace std;
long long n,m,t;
long long a[1001][1001];
struct 
{
	long long l,r,bot;
}b[1001][1001];
long long go(long long k,long long x1,long long x2,long long y,long long t)
{
	long long i;
	for(i=y;i>=0&&i<m&&a[x1][i]&&a[x2][i]&&t;i+=k,t--){}
	if(i!=y)	return i-k;
	return i;
}
int main()
{
	long long t,i,j,k,t1,t2,ans;
	char c;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				while(c=getchar())
					if(c=='R'||c=='F')	break;
				if(c=='R')	a[i][j]=0;
				else if(c=='F')	a[i][j]=1;
			}
		}
		memset(b,-1,sizeof(b));
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]==1)
				{
					t1=t2=99999;
					for(k=0;k+i<n&&a[k+i][j];k++)
					{
						b[i+k][j].bot=i;
						b[i+k][j].l=go(-1,i,i+k,j,t1);
						b[i+k][j].r=go(1,i,i+k,j,t2);
						t1=min(t1,1+j-b[i+k][j].l);
						t2=min(t2,1+b[i+k][j].r-j);
						a[i+k][j]=2;
					}
				}
			}
		}
		ans=0;
		for(i=0;i<n;i++)	for(j=0;j<m;j++)	if(b[i][j].bot!=-1)
			ans=max(ans,(b[i][j].r-b[i][j].l+1)*(i-b[i][j].bot+1));
		cout<<ans*3<<endl;
	}
	return 0;
}
