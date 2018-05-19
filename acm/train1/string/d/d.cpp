#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define reset(a,b) memset(a,b,sizeof(a))
int main()
{
	long int n,i,j,k;
	char s[1000001];
	long int *m;
	m=new long[1000000+1];
	reset(m,0);
	scanf("%s",s+1);
	s[0]='a';
	n=strlen(s)-1;
	j=0;
	for(i=2;i<=n;i++)
	{
		while(j>0&&s[j+1]!=s[i])	j=m[j];
		if(s[j+1]==s[i])	j++;
		m[i]=j;
	}
	printf("%ld",n-m[n]);
	return 0;
}