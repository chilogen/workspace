/*
  
                                _oo0oo_
                               088888880
                               88" . "88
                               (| -_- |)
                                0\ = /0
                             ___/'---'\___
                          .' \\\\|     |// '.
                         / \\\\|||  :  |||// \\
                        /_ ||||| -:- |||||-  \\
                        |   | \\\\\\  -  /// ||
                        | \_|  ''\---/''  |_/ |
                        \  .-\__  '-'  __/-.  /
                      ___'. .'  /--.--\  '. .'___
                   ."" '<  '.___\_<|>_/___.' >'  "".
                  | | : '-  \'.;'\ _ /';.'/ - ' : | |
                  \  \ '_.   \_ __\ /__ _/   .-' /  /
              ====='-.____'.___ \_____/___.-'____.-'=====
                                '=---='

            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
             AC  AC  AC  AC  AC  AC  AC  AC  AC  AC  AC  AC
     
*/
#define OJ
#include <bits/stdc++.h>
#define pb push_back
#define _1 first
#define _2 second
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define MAX(a,b)  a>b?a:b
#define MIN(a,b)  a>b?b:a
#define INF 1000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
int n,m,a[1001][1001],dp[1001][1001];
int main()
{
	#ifndef OJ
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	#endif
  int i,j,k,l;
  int x1,x2,x3,x4,y1,y2,y3,y4;
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++) scanf("%d",&a[i][j]);
  reset(dp,-1);  dp[1][1]=a[1][1];
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      x1=i-1; y1=j;
      x2=i;   y2=j-1;
      x3=i-2; y3=j-1;
      x4=i-1; y4=j-2;
      if(x1>0&&y1>0)
        dp[i][j]=MAX(dp[i][j],dp[x1][y1]+a[i][j]);
      if(x2>0&&y2>0)
        dp[i][j]=MAX(dp[i][j],dp[x2][y2]+a[i][j]);
      if(x3>0&&y3>0)
        dp[i][j]=MAX(dp[i][j],dp[x3][y3]+a[i][j]);
      if(x4>0&&y4>0)
        dp[i][j]=MAX(dp[i][j],dp[x4][y4]+a[i][j]);
      if(dp[i][j]<0)  dp[i][j]=-INF;
    }
  }
  k=0;
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
      if(dp[i][j]>k)  k=dp[i][j];
  printf("%d",k);
	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
  return 0;
}
