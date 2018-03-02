//#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int BestValue(int row[],int col[], int n)
{
	int i,j,k,l;
	int **dp;
	int inf=(-1)^(1<<sizeof(int)*4);
	inf=-inf;

	for(i=0;i<n-1;i++)
	{
		if(col[i]!=row[i+1])
		{
			cout<<"error";
			return 1;
		}
	}
	dp=new int* [n];
	for(i=0;i<n;i++)
	{
		dp[i]=new int[n];
		for(j=0;j<n;j++)	dp[i][j]=inf;
		dp[i][i]=0;
	}
	
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=i+k+1;j<n&&j-i<=2*k+1;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][i+k]+dp[i+k+1][j]+row[i]*col[j]*col[k]);
			}
		}
	}
	cout<<dp[0][n-1];
	return dp[0][n-1];
}

int main()
{
	int r[10],c[10],n,i,j;
	for(i=0;i<3;i++)
		cin>>r[i]>>c[i];
	cout<<BestValue(r,c,3);
	return 0;
}