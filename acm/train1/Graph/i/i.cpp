#include <cstdio>
#include <cmath>
#include <cstring>

int n;
unsigned short int mark[32767];
int size;
unsigned short int higbit(unsigned short int x)
{
	return x>>n<<n;
}
long int time=0;
int dfs(unsigned short int x)
{
	time++;
	if(size==0&&x==1)	return 1;//find
	if(size==0&&x!=1)	return 0;//not find
	unsigned short m0=x<<1,m1=(x<<1)+1;
	m0-=higbit(m0);	m1-=higbit(m1);
	int ans=0;
	if(!mark[m1])
	{
		size--;
		mark[m1]=1;
		ans=dfs(m1);
		if(ans)	{printf("1");	return ans;}
		size++;
		mark[m1]=0;
	}
	return ans;
	if(!mark[m0])
	{
		size--;
		mark[m0]=1;
		ans=dfs(m0);
		if(ans)	{printf("0");	return ans;}
		size++;
		mark[m0]=0;
	}//swap 1 and 0 will occur O(xuan)
}
int main()
{
	scanf("%d",&n);
	size=pow(2,n);
	memset(mark,0,sizeof(mark));
	dfs(1);
	printf("\n执行次数：%ld\n",time);
	return 0;
}
