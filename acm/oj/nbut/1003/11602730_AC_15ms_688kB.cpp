#include<iostream>
using namespace std;
int BestValue(int row[],int col[], int n)
{
	int i,j,k,l;
	int **dp;
	int inf=1<<30;

	dp=new int* [n];
	for(i=0;i<n;i++)
	{
		dp[i]=new int[n];
		for(j=0;j<n;j++)	dp[i][j]=inf;
		dp[i][i]=0;
	}

	for(l=1;l<n;l++)
	{
		for(i=0;i<n;i++)
		{
			j=i+l;
			if(j>=n)	break;
			for(k=i;k<j;k++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+row[i]*col[k]*col[j]);
		}
	}

	cout<<dp[0][n-1]<<endl;
	return dp[0][n-1];
}
int main()
{
	int r[210],c[210],n,i,j,k;
	int a[210];
	//freopen("abc.in","r",stdin);
	while(cin>>n)
	{
	for(i=0;i<=n;i++)	cin>>a[i];
	for(i=0;i<n;i++)	r[i]=a[i];
	for(i=1;i<=n;i++)	c[i-1]=a[i];
	BestValue(r,c,n);
	}
	return 0;
}
