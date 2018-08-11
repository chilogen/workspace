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
struct cmp
{
  bool operator()(const long int &a,const long int &b)
  { return a<b;}
};
int main()
{
	#ifndef OJ
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	#endif
  long int n,a,b,i,j,k,l,o,p,m;
  priority_queue<long int,vector<long int>,cmp>q[2];
  scanf("%ld%ld%ld",&n,&a,&b);
  for(i=1;i<=n;i++)
  {
    scanf("%ld",&j);
    q[0].push(j);
  }
  i=0;  m=1;
  while(1)
  {
    n=!m;
    if(q[n].empty())  break;
    j=q[n].top();
    q[n].pop();
    k=j/a;
    if(k==0)  k=1;
    i+=k;
    o=a*k;
    p=b*k;
    j-=o;
    if(j>0) q[m].push(j);
    while(!q[n].empty())
    {
      j=q[n].top();
      q[n].pop();
      j-=p;
      if(j>0) q[m].push(j);
    }
    m=n;
  }
  printf("%ld",i);
	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
}