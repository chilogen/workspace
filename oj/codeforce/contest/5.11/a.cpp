#include <cstdio>
int main()
{
	int n,t,k,d;
	scanf("%d%d%d%d",&n,&t,&k,&d);
	int t1,t2;
	if(k>=n)	t1=t;
	else if(n%k==0)	t1=n/k*t;
	else t1=(n/k+1)*t;
	t1--;
	if((t1-d)/t*k+t1/t*k>=n)	printf("YES");
	else printf("NO");
	return 0;
}