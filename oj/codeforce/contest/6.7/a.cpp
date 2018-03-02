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
bool cmp(const int &a,const int &b)
{
  return a>b;
}
int main()
{
	#ifndef OJ
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	#endif
  int n,k;
  int a[200],b[200];
  int i,j,l;
  scanf("%d%d",&n,&k);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<k;i++)
    scanf("%d",&b[i]);
  sort(b,b+k,cmp);
  for(i=0,j=0;i<n;i++)
  {
    if(a[i]==0)
    {
      a[i]=b[j];
      j++;
    }
  }
  l=0;
  for(i=1;i<n;i++)
  {
    if(a[i]<a[i-1]) {l=1;break;}
  }
  if(l==1) printf("Yes\n");
  else printf("No\n");
	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
}