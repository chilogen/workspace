//
// Created by a on 12/25/17.
//

#include <life.h>

int getsum(int x,int y)
{
    int sx,sy,ex,ey,i,j,ans=0;
    sx=(x==1?1:x-1);
    sy=(y==1?1:y-1);
    ex=(x==pixelx?pixelx:x+1);
    ey=(y==pixely?pixely:y+1);
    for(i=sx;i<=ex;i++)
        for(j=sy;j<=ey;j++)
            ans+=(m[i][j]?1:0);
    ans-=(m[x][y]?1:0);
    return ans;
}

void evolution()
{
    int i,j,s;
    memset(temp,0,sizeof(temp));
    for(i=1;i<=pixelx;i++)
        for(j=1;j<=pixely;j++)
        {
            s=getsum(i,j);
            if(s<2||s>3)    temp[i][j]=0;
            else if(s==2)   temp[i][j]=m[i][j];
            else if(s==3)   temp[i][j]=1;
        }
    memcpy(m,temp,sizeof(temp));
    usleep(sleeptime);
}