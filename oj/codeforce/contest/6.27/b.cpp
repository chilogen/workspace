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
#include <bits/stdc++.h>
#define pb push_back
#define _1 first
#define _2 second
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define MAX(a,b)  a>b?a:b
#define mi(a,b)  a>b?b:a
const double PI=3.1415926535898;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

double per,the1,the2,the3,a,b,c;
int ans[3];
double  mi=1000;
double x[100001],y[100001];
double dis(int n1,int n2)
{
  return sqrt((x[n1]-x[n2])*(x[n1]-x[n2])+(y[n1]-y[n2])*(y[n1]-y[n2]));
}
int main()
{
  long long n,a,i,j,v1,v2,v3;
  bool update;
  cin>>n>>a;
  per=360/(double)n;
  for(i=1;i<=n;i++)
  {
    x[i]=cos((per*(i-1))/180*PI);
    y[i]=sin((per*(i-1))/180*PI);
  }
  ans[0]=1; ans[1]=2; ans[2]=3;
  v2=1;
  for(i=1;i<=n/2;i++)
    for(j=1;j<=n&&j+i<=n;j++)
      {
          v1=v2+i;  v3=v2+j;
          a=dis(v1,v3);
          b=dis(v2,v3);
          c=dis(v1,v2);
          the2=acos((b*b+c*c-a*a)/(2*b*c))/PI*180;
          the1=acos((a*a+c*c-b*b)/(2*a*c))/PI*180;
          the3=acos((a*a+b*b-c*c)/(2*a*b))/PI*180;
          update=false;
          if(the2< mi)
          {
            mi=the2;
            update=true;
          }
          if(the3<mi)
          {
            mi=the3;
            update=true;
          }
          if(the1<mi)
          {
            mi=the1;
            update=true;
          }
          if(update==true)
          {
            ans[0]=v1;
            ans[1]=v2;
            ans[2]=v3;
          }
      }
    for(i=0;i<3;i++)
      cout<<ans[i]<<" ";
    return 0;
}