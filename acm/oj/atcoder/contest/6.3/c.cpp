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
  {
    return a>b;
  }
};
int main()
{
	#ifndef OJ
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	#endif
  long int n,ans=0;
  long int i,j,k,l;
  priority_queue <long int,vector <long int>,cmp>q;
  scanf("%ld",&n);
  for(i=1;i<=n;i++)
   {
    scanf("%ld",&j);
    ans+=j;
    q.push(j);
   }
   while(ans%10==0)
   {
    if(q.empty()) break;
    i=q.top();
    q.pop();
    if((ans-i)%10==0) continue;
    ans-=i;
   }
  if(ans%10==0) printf("0");
  else printf("%ld",ans);
	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
}