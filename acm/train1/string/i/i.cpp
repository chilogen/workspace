#include <bits/stdc++.h>
using namespace std;
int ans[1000][10],k=0;;
void output()
{
  int i;
  for(i=0;i<9;i++) 
    ans[k+1][i]=ans[k][i];
  k++;
}
void queen(int l,int c,int r,int n)
{
  if(n==9) {output(); return ;}
  int i,j;
  int ll,cc,rr;
  for(i=1;i<=9;i++)
  {
    j=1<<i;
    if(((j&l)==0)&&((j&c)==0)&&((j&r)==0))
    {
      ans[k][n]=i;
      ll=l<<1;  cc=c; rr=r>>1;
      queen(ll|(1<<i+1),cc|(1<<i),rr|(1<<i-1),n+1);
    }
  }
}
int main()
{
  int l=0,c=0,r=0;
  int i,j;
  for(i=1;i<=9;i++)
  {
    l=1<<(i+1);
    c=1<<i;
    r=1<<(i-1);
    ans[k][0]=i;
    queen(l,c,r,1);
  }
  printf("%d\n",k);
  for(i=0;i<k;i++)
  {
    for(j=0;j<9;j++)
      printf("%d ",ans[i][j]);
    printf("\n");
  }
  return 0;
}