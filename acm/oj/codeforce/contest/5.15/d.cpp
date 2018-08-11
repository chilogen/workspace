#include <bits/stdc++.h>
using namespace std;
long int obj[100000],f[50001];
long sum=0;
long int max(long int a,long int b)
{
	if(a>b)	return a;
	else return b;
}
int main()
{
	int n,i,j,k,l;
	scanf("%d",&n);
	memset(f,-1,sizeof(f));
	f[0]=0;
	for(i=0;i<n;i++){scanf("%ld",&obj[i]);sum+=obj[i];}
	if(sum%2!=0){printf("NO");return 0;}
	else
	{
		sum=sum/2;
		i=0;
		while(f[0]!=sum&&i<n)
		{
			for(j=sum;j>=0;j--)
				f[j]=max(f[j],f[j-obj[i]]+obj[i]);
			i++;
		}
	}
	if(f[0]==sum)	printf("YES");
	else printf("NO");
	return 0;
}