/*
  
                                _oo0oo_
                               088888880
                               88" . "88
                               (| -_- |)
                                0\ = /0
                             ___/'---'\___
                           .' \\\\|     |// '.
                          / \\\\|||  :  |||// \\
                         /_ ||||| -:- |||||- \\
                        |   | \\\\\\  -  /// |   |
                        | \_|  ''\---/''  |_/ |
                        \  .-\__  '-'  __/-.  /
                      ___'. .'  /--.--\  '. .'___
                   ."" '<  '.___\_<|>_/___.' >'  "".
                  | | : '-  \'.;'\ _ /';.'/ - ' : | |
                  \  \ '_.   \_ __\ /__ _/   .-' /  /
              ====='-.____'.___ \_____/___.-'____.-'=====
                                '=---='

            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                      	GOD SAVE		I WANT AC
     
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
using namespace std;
int main()
{
	#ifndef OJ
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	#endif
  int n,m,r[103],l[103],dp[103][2],ans[103],i,j,k;
  reset(ans,-1);
  char s[103];
  scanf("%d%d",&n,&m);
  m+=2;
  for(i=1;i<=n;i++)
  {
    scanf("%s",s);
    r[i]=1; l[i]=m;
    for(j=1;j<=m;j++)
    {
      k=s[j-1]-'0';
      if(k==1)
      {
        r[i]=j;
        if(l[i]==m) l[i]=j;
      }
    }
  }
  dp[n][0]=(r[n]-1)*2;  dp[n][1]=m-1;
  ans[n]=r[n]-1;
  for(i=n-1;i>=1;i--)
  {
    dp[i][0]=MIN(dp[i+1][1]+m,dp[i+1][0]+1+2*(r[i]-1));
    dp[i][1]=MIN(dp[i+1][0]+m,dp[i+1][1]+1+2*(m-l[i]));
    if(l[i]==m) ans[i]=ans[i+1];
    else  ans[i]=MIN(dp[i+1][0]+r[i],dp[i+1][1]+1+m-l[i]);
  }
  printf("%d",ans[1]);
  #ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
  return 0;
}