#include <bits/stdc++.h>
using namespace std;
int m[4][4];
long long move(int row[4],int col[4])
{
	int i,j,x,y;
	long long ans=0;
	int temp[4][4],c[4],r[4];
	for(i=0;i<4;i++)	for(j=0;j<4;j++)	temp[i][j]=m[row[i]][col[j]];
	for(i=0;i<4;i++)	
	{
		for(j=0;j<4;j++)
		{
			if(temp[i][j]!=4*i+j+1)
			{
				x=(temp[i][j]-1)/4;
				y=(temp[i][j]-1)%4;
				temp[i][j]^=temp[x][y];
				temp[x][y]^=temp[i][j];
				temp[i][j]^=temp[x][y];
				ans++;
			}
		}
		c[i]=col[i];	r[i]=row[i];
	}
	for(i=0;i<4;i++)
	{
		if(r[i]!=i)
		{
			j=r[r[i]];
			r[r[i]]=r[i];
			r[i]=j;
			ans++;
		}
		if(c[i]!=i)
		{
			j=c[c[i]];
			c[c[i]]=c[i];
			c[i]=j;
			ans++;
		}
	}
	return ans;
}
int main()
{
	int temp[4],r[24][4],c[24][4];
	long long ans,min;
	int i,j,k,l;
	for(i=0;i<4;i++)	temp[i]=i;
	j=0;
	do
	{
		for(i=0;i<4;i++)
		{
			r[j][i]=temp[i];
			c[j][i]=temp[i];
		}
		j++;
	}while(next_permutation(temp,temp+4));
	while(scanf("%d%d%d%d",&m[0][0],&m[0][1],&m[0][2],&m[0][3])!=EOF)
	{
		min=9000000000000000;
		for(i=1;i<4;i++)	for(j=0;j<4;j++)	scanf("%d",&m[i][j]);
		for(i=0;i<24;i++)	for(j=0;j<24;j++)
		{
			ans=move(r[i],c[j]);
			min=min>ans?ans:min;
		}
		cout<<min<<endl;
	}
	return 0;
}