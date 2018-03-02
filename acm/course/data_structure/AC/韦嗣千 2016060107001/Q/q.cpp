#include <cstdio>
#include <cstring>

long long int a[1001][1001];

void update(int x,int y,int v)
{
	int i,k;  
    for(i=x; i<=1000; i+=i&-i)  
        for(k=y; k<=1000; k+=k&-k)  
            a[i][k]+=v;
}
long long int query(int x,int y)
{
    int i,k;
    long long sum=0;  
    for(i=x; i>0; i-=i&-i)  
        for(k=y; k>0; k-=k&-k)  
            sum += a[i][k];  
    return sum; ;
}
int main()
{
	int t,n;
	char com;
	//freopen("abc","r",stdin);
	int x1,x2,y1,y2;
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
				printf("%lld\n",query(x1,y1)%2);
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
	//fclose(stdin);
	return 0;
}