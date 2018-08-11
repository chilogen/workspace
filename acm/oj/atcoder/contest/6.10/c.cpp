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
  int n,a,i,j,k;
  set<int> s1;
  int s2=0;
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>a;
    if(a>3199)  {s2++;  continue;}
    if(a>=1&&a<=399)  {s1.insert(1);  continue;}
    if(a>=400&&a<=799) {s1.insert(2); continue;}
    if(a>=800&&a<=1199){s1.insert(3); continue;}
    if(a>=1200&&a<=1599){s1.insert(4);continue;}
    if(a>=1600&&a<=1999){s1.insert(5);continue;}
    if(a>=2000&&a<=2399){s1.insert(6);continue;}
    if(a>=2400&&a<=2799){s1.insert(7);continue;}
    if(a>=2800&&a<=3199){s1.insert(8);continue;}
  }
  j=s1.size();
  if(j>0) cout<<j<<" ";
  else cout<<"1"<<" ";
  cout<<j+s2;
	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
}