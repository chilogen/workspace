#include <bits/stdc++.h>
using namespace std;
char a[200][200];
int n,m;
int main()
{
	int i,j,k,l;
	int b[4];
	cin>>n>>m;
	memset(a,0,sizeof(a));
	for(i=0;i<n;i++)
		scanf("%s",a[i]);
	bool dsa=false;
	if(n%3==0)
	{
		l=n/3;
		b[0]=0;	b[1]=l;	b[2]=b[1]+l;	b[3]=b[2]+l;
		for(i=0;i<3&&!dsa;i++)
		{
			for(j=b[i];j<b[i+1]&&!dsa;j++)
			{
				for(k=0;k<m;k++)
				{
					if(a[j][k]!=a[b[i]][0])	dsa=true;
				}
			}
		}
		if(!dsa)
		{
			puts("YES");
			return 0;
		}
	}
	if(m%3==0)
	{
		l=m/3;
		b[0]=0;	b[1]=l;	b[2]=b[1]+l;	b[3]=b[2]+l;
		for(i=0;i<3&&!dsa;i++)
		{
			for(j=b[i];j<b[i+1]&&!dsa;j++)
			{
				for(k=0;k<n;k++)
				{
					if(a[k][j]!=a[0][b[i]])	dsa=true;
				}
			}
		}
		if(!dsa)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}