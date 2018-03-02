#include <cstdio>
using namespace std;
int main()
{
	int i,j,k;
	char a[100001];
	char c;
	long int ans=0;
	c=getchar();
	i=1;
	while(c!='\n')
	{
		a[i]=c;
		c=getchar();
		i++;
	}
	i--;
	for(j=1;j<=i;j++)
	{
		if(a[j]=='U')
		{
			ans+=i-j;
			ans=ans+2*(j-1);
		}
		else if(a[j]=='D')
		{
			ans+=j-1;
			ans=ans+2*(i-j);
		}
	}
	printf("%ld",ans);
	return 0;
}