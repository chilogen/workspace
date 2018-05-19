#include <bits/stdc++.h>
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000009
struct mat
{
  int row,col;
  long long a[5][5];
  mat(int r,int c)
  {
    row=r;  col=c;
    int i,j;
    reset(a,0);
  }
  void setdata(long long b[5][5])
  {
    int i,j;
    for(i=0;i<row;i++)
      for(j=0;j<col;j++)
        a[i][j]=b[i][j];
  }
};
mat d(1,5),res(5,5);
mat mutm(mat &b,mat &d)
{
  int r=b.row,c=b.col,j,i,k;
  mat ans(r,c);
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      for(k=0;k<c;k++)
        ans.a[i][j]=(ans.a[i][j]+b.a[i][k]*d.a[k][j])%mod;
    }
  }
  return ans;
}
long long mutn(long long k)
{
  long long a=4,ans=1;;
  while(k)
  {
    if(k&1) ans=(ans*a)%mod;
    k=k>>1;
    a=(a*a)%mod;
  }
  return ans;
}
mat qmutm(mat a,long long k)
{
  mat ans(5,5);
  ans.a[0][0]=1;  ans.a[1][1]=1;
  ans.a[2][2]=1;  ans.a[3][3]=1;  ans.a[4][4]=1;
  while(k)
  {
    if(k&1) ans=mutm(ans,a);
    k=k>>1;
    a=mutm(a,a);
  }
  return ans;
}
void init()
{
  long long a[5][5],b[1][5];
  reset(a,0); reset(b,0);
  b[0][0]=4;b[0][1]=12;b[0][2]=12;b[0][3]=12;b[0][4]=24;
  d.setdata(b);
  a[0][0]=1;  a[0][1]=3; 
  a[1][2]=1;  a[1][3]=1;  a[1][4]=2;  
  a[2][2]=1;  a[2][3]=1;  a[2][4]=2;
  a[3][0]=1;  a[3][1]=3; 
  a[4][2]=1;  a[4][3]=1;  a[4][4]=1;
  res.setdata(a);
}
int main()
{
  long long n;
  scanf("%lld",&n);
  init();
  res=qmutm(res,n-3);
  d=mutm(d,res);
  n=mutn(n);
  int i;
  long long j=0;
  for(i=0;i<5;i++)
    j=(j+d.a[0][i])%mod;
  printf("%lld",(n+mod-j)%mod);
  return 0;
}