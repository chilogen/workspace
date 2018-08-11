#include <bits/stdc++.h>
#define reset(a,b) memset(a,b,sizeof(a))
using namespace std;
char a[1001][200];
int main()
{
	freopen("alignment.in","r",stdin);
	freopen("alignment.out","w",stdout);
	char ch;
	int space[1001][200],ind[1001][200];
	reset(a,0);
	reset(space,-1);
	reset(ind,-1);
	int i,j,k,l;
	int r,c;
	r=k=0;	c=1;
	while(scanf("%c",&ch)!=EOF)
	{
		if(ch=='\n')
		{
			r++;
			k=0;
			c=1;
			continue;
		}
		if(ch!=' '&&a[r][c-1]=='\0')
		{
			ind[r][k]=c;
			k++;
		}
		if(ch==' ')	a[r][c]='\0';
		else	a[r][c]=ch;
		c++;
	}
	for(i=0;i<180;i++)
	{
		int len=-1;
		for(j=0;j<=r;j++)
		{
			if(ind[j][i]==-1)
			{
				space[j][i]=1;
				continue;
			}
			len=max(len,(int)strlen(a[j]+ind[j][i]));
		}
		for(j=0;j<=r;j++)
		{
			if(ind[j][i]==-1)	continue;
			space[j][i+1]=len-strlen(a[j]+ind[j][i])+1;
		}
	}
	for(i=0;i<=r;i++)
	{
		for(j=0;j<180;j++)
		{
			if(ind[i][j]==-1)	{break;}
			for(k=0;k<space[i][j];k++)	printf(" ");
			printf("%s",a[i]+ind[i][j]);
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}