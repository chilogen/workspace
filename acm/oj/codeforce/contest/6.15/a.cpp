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
  int n,x1,x2,y1,y2,x,y,a,b,c;
  cin>>x1>>y1>>x2>>y2>>x>>y;
  a=abs((x1-x2)%x);  b=abs((y1-y2)%y);
  if(a!=0||b!=0){cout<<"NO";  return 0;}
  a=abs((x1-x2)/x);  b=abs((y1-y2)/y);
  if((b-a)%2==0)  {cout<<"YES"; return 0;}
  cout<<"NO";
	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
}