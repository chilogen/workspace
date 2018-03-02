#include <bits/stdc++.h>
#define reset(a,b) memset(a,b,sizeof(a))
#define MAX(a,b)  a>b?a:b
#define MIN(a,b)  a>b?b:a
#define INF (1e19+1e18)
using namespace std;
struct cmp
{
  bool operator()(const unsigned long &a,const unsigned long &b)
  {
    return a>b;
  }
};
int main()
{
  unsigned long int x,y,s,e,t;
  scanf("%lu%lu%lu%lu",&x,&y,&s,&e);
  int i,j,k,l,m=0;
  unsigned long int a[70],b[70];
  priority_queue<unsigned long,vector<unsigned long>,cmp> q;
  reset(a,0); reset(b,0);
  a[0]=1; b[0]=1;
  for(i=1;;i++)
  {
      if(x==1)  break;
      if(INF/a[i-1]<x)  break;
      if(a[i-1]>=e)  break;
      a[i]=a[i-1]*x;
  }
  for(j=1;;j++)
  {
    if(y==1)  break;
    if(INF/b[j-1]<y)  break;
    if(b[j-1]>=e)  break;
    b[j]=b[j-1]*y;
  }
  for(k=0;k<i;k++)
  {
    for(l=0;l<j;l++)
    {
      x=a[k]+b[l];
      if(x>e) continue;
      if(x<s) continue;
      q.push(x);
    }
  }
  if(q.empty()) {printf("%lu",e-s+1);  return 0;}
  x=q.top();
  t=x-s;
  while(!q.empty())
  {
    y=q.top();
    q.pop();
    if(x==y)  continue;
    t=MAX(y-x-1,t);
    x=y;
  }
  t=MAX(t,e-x);
  printf("%lu\n",t);
}