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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

int d[1<<21],n;
int p[21][21][21];
int dp(int s)
{
  if(d[s]!=-1)  return d[s];
  int i,j,k,l;
  for(i=0;i<n-2;i++)
    if(s&(1<<i))  break;
  for(j=i+1;j<n-1;j++)
    if(s&(1<<j))
      for(k=j+1;k<n;k++)
        if(s&1<<k)
          d[s]=MAX(d[s],dp(s^(1<<i)^(1<<j)^(1<<k))+p[i][j][k]);
  return d[s];
}
int main()
{
	#ifndef OJ
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	#endif
  int i,j,k,l,m;
  scanf("%d",&n);
  for(i=0;i<n*(n-1)*(n-2)/6;i++)
  {
    scanf("%d%d%d%d",&j,&k,&l,&m);
    p[j-1][k-1][l-1]=m;
  }
  int s=(1<<n)-1;
  reset(d,-1);
  d[0]=0;
  dp(s);
  printf("%d",d[s]);
	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
}