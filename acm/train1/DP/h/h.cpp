#include <bits/stdc++.h>
#define MAX(a,b)  a>b?a:b
using namespace std;
int main()
{
  int n,m,i,j,k,l,x1,y1,x2,y2;
  unsigned int max;
  unsigned int **l1,**l2,**r1,**r2,**a;
  a=new unsigned *[1003];
  l1=new unsigned *[1003];
  l2=new unsigned *[1003];
  r1=new unsigned *[1003];
  r2=new unsigned *[1003];
  for(i=0;i<1003;i++)
  {
    a[i]=new unsigned [1003];
    l1[i]=new unsigned [1003];
    l2[i]=new unsigned [1003];
    r1[i]=new unsigned [1003];
    r2[i]=new unsigned [1003];
  }
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%u",&a[i][j]);
  for(i=1;i<=n;i++) for(j=1;j<=m;j++)
  {
    x1=i-1; y1=j;
    x2=i; y2=j-1;
    if(x1>=0)  l1[i][j]=MAX(l1[i][j],l1[x1][y1]+a[i][j]);
    if(y2>=0)  l1[i][j]=MAX(l1[i][j],l1[x2][y2]+a[i][j]);
  }
  for(i=n;i>=1;i--) for(j=1;j<=m;j++)
  {
    x1=i+1; y1=j;
    x2=i; y2=j-1;
    l2[i][j]=0;
    if(x1<=n+1) l2[i][j]=MAX(l2[i][j],l2[x1][y1]+a[i][j]);
    if(y2>=0) l2[i][j]=MAX(l2[i][j],l2[x2][y2]+a[i][j]);
  }
  for(i=1;i<=n;i++) for(j=m;j>=1;j--)
  {
    x1=i-1; y1=j;
    x2=i; y2=j+1;
    r1[i][j]=0;
    if(x1>=0) r1[i][j]=MAX(r1[i][j],r1[x1][y1]+a[i][j]);
    if(y2<=m+1) r1[i][j]=MAX(r1[i][j],r1[x2][y2]+a[i][j]);
  }
  for(i=n;i>=1;i--) for(j=m;j>=1;j--)
  {
    x1=i+1; y1=j;
    x2=i; y2=j+1;
    r2[i][j]=0;
    if(x1<=n+1) r2[i][j]=MAX(r2[i][j],r2[x1][y1]+a[i][j]);
    if(y2<=m+1) r2[i][j]=MAX(r2[i][j],r2[x2][y2]+a[i][j]);
  }
  max=0;
  for(i=2;i<n;i++) for(j=2;j<m;j++)
  {
      max=MAX(max,l1[i-1][j]+r2[i+1][j]+l2[i][j-1]+r1[i][j+1]);
      max=MAX(max,l1[i][j-1]+r2[i][j+1]+l2[i+1][j]+r1[i-1][j]);
  }
  printf("%u",max);
  return 0;
}