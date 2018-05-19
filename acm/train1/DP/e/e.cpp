#include <bits/stdc++.h>
#define RATE 1000
struct block
{
	int r,dist;
}a;
using namespace std;
struct cmp
{
	bool operator()(const block &a,const block &b)	{return a.dist>b.dist;}
};
int main()
{
	//freopen("abc.in","r",stdin);
	int m,k,n,p,i,j,l,point=0;
	double road[2][30001],ans=RATE;
	priority_queue <block,vector<block>,cmp> q;
	memset(road,0,sizeof(road));
	scanf("%d%d%d%d",&m,&k,&n,&p);
	road[point][p]=RATE;
	for(i=0;i<k;i++)
	{
		scanf("%d%d",&a.r,&a.dist);
		q.push(a);
	}
	if(k==0)
	{
		printf("1.000000");
		return 0;
	}
	a=q.top();	q.pop();
	if(m==1)
	{
		for(i=1;i<=n;i++)
		{
			if(a.dist==i)	break;
		}
		if(n>=i)	printf("0.000000");
		else printf("1.000000");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		l=!point;
		for(j=1;j<=m;j++)
		{
			if(j==1&&m==3)
			{
				road[l][j]=road[point][1]/2+road[point][2]/3;
				j++;
				road[l][j]=road[point][1]/2+road[point][2]/3+road[point][3]/2;
				j++;
				road[l][j]=road[point][2]/3+road[point][3]/2;
				continue;
			}
			if(j==1&&m==2)
			{
				road[l][j]=road[point][1]/2+road[point][2]/2;
				j++;
				road[l][j]=road[point][1]/2+road[point][2]/2;
				continue;
			}
			if(j==1&&m>3)
			{
				road[l][j]=road[point][1]/2+road[point][2]/3;
				j++;
				road[l][j]=road[point][1]/2+road[point][2]/3+road[point][3]/3;
				continue;
			}
			if(j==m-1)
			{
				road[l][j]=road[point][j-1]/3+road[point][j]/3+road[point][j+1]/2;
				j++;
				road[l][j]=road[point][j-1]/3+road[point][j]/2;
				continue;
			}
			road[l][j]=road[point][j-1]/3+road[point][j]/3+road[point][j+1]/3;
		}
		point=l;
		while(a.dist==i)
		{
			ans-=road[point][a.r];	road[point][a.r]=0;
			if(q.empty())	break;
			a=q.top();	q.pop();
		}
	}
	printf("%.6lf",ans/RATE);
	//fclose(stdin);
	return 0;
}
