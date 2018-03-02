#include<bits/stdc++.h>
using namespace std;
#define maxn 105
char s[maxn][maxn];
int r[2],c[2];
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",s[i]);
    r[1]=-1,c[1]=-1;
    r[0]=n+1,c[0]=m+1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='B')
            {
                r[0]=min(r[0],i);
                c[0]=min(c[0],j);
                r[1]=max(r[1],i);
                c[1]=max(c[1],j);
            }
        }
    }
    if(r[1]==-1){puts("1");return 0;}
    int x=r[1]-r[0]+1,y=c[1]-c[0]+1;
    if(x>m || y>n){puts("-1");return 0;}
    int cnt=0;
    for(int i=r[0];i<=r[1];i++)
        for(int j=c[0];j<=c[1];j++)if(s[i][j]=='W')cnt++;
    if(x>y)cnt+=x*(x-y);
    else cnt+=y*(y-x);
    printf("%d\n",cnt);
    return 0;
}