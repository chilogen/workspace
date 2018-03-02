#include <cstdio>
#include <cstring>

int a[1001][1001];

void update(int x,int y,int v)
{
	while(x<=1000)
	{
		while(y<=1000)
		{
			a[x][y]+=v;
			y+=y&-y;
		}
		x+=x&-x;
	}
}
int query(int x,int y)
{
	int ans=0;
	while(x>0)
	{
		while(y>0)
		{
			ans+=a[x][y];
			y-=y&-y;
		}
		x-=x&-x;
	}
	return ans;
}
int main()
{
	int t,n;
	char com;
	int x1,x2,y1,y2;
	freopen("abc","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		while(n--)
		{
			com=getchar();
			while(com!='C'&&com!='Q')	
				com=getchar();
			if(com=='Q')
			{
				scanf("%d%d",&x1,&y1);
				printf("%d\n",query(x1,y1)%2);
			}
			else
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				update(x1,y1,1);
				update(x1,y2+1,-1);
				update(x2+1,y1,-1);
				update(x2+1,y2+1,1);
			}
		}
	}
	fclose(stdin);
	return 0;
}
