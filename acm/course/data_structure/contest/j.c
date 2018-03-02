#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	int n,len;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",a);
		len=strlen(a);
		printf("%d\n",len);
	}
	return 0;
}