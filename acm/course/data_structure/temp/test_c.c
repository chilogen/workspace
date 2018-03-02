#include<stdio.h>
#include<stdlib.h>
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int main()
{
	int s,n;
	scanf("%d%d",&n,&s);
	freopen("abc","w",stdout);
		srand(s);
		int q=rand()%30;
		printf("%d %d\n",n,q);
		for(int i=0;i<n;i++)
		printf("%d ",rand()%50);
		printf("\n");
		int p=rand()%50;
		printf("%d\n",p);
		for(int i=0,op,x,y,c;i<p;i++)
		{
			op=rand()%3+1;
			x=rand()%n+1;
			y=rand()%n+1;
			printf("%d %d %d ",op,x+y-max(x,y),max(x,y));
			if(op==3)
			{
				printf("\n");
			}
			else 
			{
				c=rand()%40;
				printf("%d\n",c);
			}
		}
		fclose(stdout);
	return 0;
}