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
  int n;
  int a[1000],b[1000],p[1000],c[2],d[2];
  set <int> s;
  int i,j,k,l;
  scanf("%d",&n);
  reset(p,-1);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n;i++)
    scanf("%d",&b[i]);
  for(i=0,j=0;i<n;i++)
  {
    if(a[i]==b[i])  {p[i]=a[i]; s.insert(a[i]);}
    else
    {
      c[j]=i; j++;
    }
  }
  for(i=1,k=0;i<=n;i++)
  {
    if(s.count(i)==0) {d[k]=i;  k++;}
  }
  if(j==1)
  {
    for(i=1;i<=n;i++)
      if(s.count(i)==0) {p[c[0]]=i; break;}
  }
  else if(j==2)
  {
    if(d[0]==a[c[0]]&&d[0]!=b[c[0]]&&d[1]==b[c[1]]&&d[1]!=a[c[1]])
    {
      p[c[0]]=d[0]; p[c[1]]=d[1];
    }
    else if(d[0]==b[c[0]]&&d[0]!=a[c[0]]&&d[1]==a[c[1]]&&d[1]!=b[c[1]])
    {
      p[c[0]]=d[0]; p[c[1]]=d[1];
    }
    else
    {
      p[c[0]]=d[1]; p[c[1]]=d[0];
    }
  }
  for(i=0;i<n;i++)
    printf("%d ",p[i]);
	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
}