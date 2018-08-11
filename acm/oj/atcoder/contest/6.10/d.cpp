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

int main()
{
	#ifndef OJ
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	#endif
  int n,a[100],b[100],c[100];
  char d[105];
  scanf("%d%s",&n,d);
  int i,j,k;
  for(i=0;i<n;i++)  
    if(d[i]=='(')  a[i]=0;
    else a[i]=1;
  for(k=1;k<n;k++)
  {
    j=k-1;
    if(a[j]==0&&a[k]==1)
    { 
      for(i=j;i<n-2;i++)
        a[i]=a[i+2];
      n-=2; k-=2;
    }
  }
  for(i=0;a[i]!=0&&i<n;i++)
    printf("(");
  printf("%s",d);
  for(;i<n;i++)
    printf(")");
	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
}