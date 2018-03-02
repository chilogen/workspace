#include <bits/stdc++.h>
using namespace std;
#define reset(a,b)	memset(a,b,sizeof(a))
int num[305][305],a[305][305];
inline int query(int x,int y,int i,int j)
{
	return num[i][j]-num[i][y-1]-num[x-1][j]+num[x-1][y-1];
}
int main()
{
	int t,r,c,i,j,k,x,y,ans,one,zero;
	cin>>t;
	while(t--)
	{
		reset(num,0);	ans=0;
		cin>>r>>c;
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				cin>>a[i][j];
				num[i][j]=num[i-1][j]+num[i][j-1]-num[i-1][j-1]+a[i][j];
				for(k=1;;k++)
				{
					x=i-k;	y=j-k;
					if(x<1||y<1)	break;
					one=query(x,y,i,j);	zero=(k+1)*(k+1)-one;
					one=one-4*k;
					x=query(x+1,y+1,i-1,j-1);
					if(one<0||abs(one-zero)>1||one!=x)	continue;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}