#include<stdio.h>
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int min(int x,int y)
{
	if(x>y) return y;
	return x;
}
int main()
{
	int k,x,y,lop,tx,ty;
	scanf("%d%d",&x,&y);
	if(max(x,y)%min(x,y)==0)
	{
		printf("%d",max(x,y));
		return 0;
	}
	tx=x; ty=y;
	k=max(x,y)%min(x,y);
	while(k!=0)
	{
		x=min(x,y);
		y=k;
		k=max(x,y)%min(x,y);
	}
	printf("%d",max(x,y)/min(x,y)*max(tx,ty));
	return 0;
}
