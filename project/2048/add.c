#include"include.h"
int add(int p[4])
{
       int appear=0,count0=0,i,j,zero=-1;
       for(i=0;i<4;i++)
       {
                if(p[i]!=0)
                for(j=i+1;j<4;j++)
                {
                        if(p[j]==0)     continue;
                        if(p[i]==p[j])  {p[i]*=2; p[j]=0; appear=1;     break;}
                        else break;
                }
        }
        for(i=0;i<4;i++)
        {
                if(p[i]==0&&zero==-1)    zero=i;
                if(p[i]==0)     count0++;
        }
        if(count0==4)   return 2;
        for(i=zero+1;i<4&&zero!=-1;i++)
        {
                if(p[i]!=0)     {p[zero]=p[i];  p[i]=0; zero++; appear=1;}
        }
       return appear;
}
void append(int q[4],int i,int j,int m[4][4])
{
	int k,x;
	x=0;
	for(k=0;k<4;k++)
		if(q[k]==1) x++;
        for(k=0;k<4&&x>0;k++)
                if(q[k]==2) x++;
	if(x==0) return;
	srand((unsigned)time(NULL));
	x=rand()%x+1;
	for(k=0;x>0;k++)
	{
		if(q[k]!=0) x--;
	}
	if(i>j) i=k-1;
	else j=k-1;
	if(rand()%5==1) map[i][j]=4;
	else m[i][j]=2;
}
