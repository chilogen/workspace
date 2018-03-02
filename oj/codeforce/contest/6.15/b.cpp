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
  long long n,a[100000],i,j,k,l,b[3]={0};
  cin>>n;
  for(i=0;i<n;i++)
    scanf("%lld",&a[i]);
  sort(a,a+n);
  for(i=0;i<n;i++)
  {
    if(a[i]=a[0]) {b[0]++;  continue;}
    if(a[i]=a[1]) {b[1]++;  continue;}
    if(a[i]=a[2]) {b[2]++;  continue;}
  }
  if(b[0]!=0&&b[1]!=0&&b[2]!=0)
  {
    cout<<b[0]*b[1]*b[2];
    return 0;
  }
  if(b[1]==0&&b[2]==0)
  {
    cout<<C(a[0],3);
    return 0;
  }
  if(b[2]==0)
  {
    cout<<
  }
	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
  return 0;
}