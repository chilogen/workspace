#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	scanf("%s%s",a,b);
	int i,j,n;
	n=strlen(b);
	for(i=0;i<strlen(a)-n+1;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i+j]!=b[j]) break;
		}
		if(j==n) break;
	}
	if(i<strlen(a)-n+1) printf("%d",i+1);
	return 0;
}
