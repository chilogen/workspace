#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL b[4];
void merge()
{
	LL i,j,k;
	for(i=0;i<3;i++)
	{
		if(b[i]==0)	continue;
		for(j=i+1;j<4;j++)
		{
			if(b[j]!=0&&b[j]!=b[i])	break;
			if(b[j]!=0&&b[j]==b[i])
			{
				b[i]*=2;
				b[j]=0;
				break;
			}
		}
	}
	for(i=0;i<3;i++)
	{
		if(b[i]==0)
		{
			for(j=i+1;j<4;j++)
			{
				if(b[j]!=0)
				{
					b[i]=b[j];
					b[j]=0;
					break;
				}
			}
		}
	}
}
int main()
{
	LL a[4][4],i,j,k,op;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)	cin>>a[i][j];
	cin>>op;
	if(op==0)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			b[j]=a[i][j];
			merge();
			for(j=0;j<4;j++)
			a[i][j]=b[j];
		}
	}
	else if(op==1)
	{
		for(j=0;j<4;j++)
		{
			for(i=0;i<4;i++)
			b[i]=a[i][j];
			merge();
			for(i=0;i<4;i++)
			a[i][j]=b[i];
		}
	}
	else if(op==2)
	{
		for(i=0;i<4;i++)
		{
			for(j=3,k=0;j>=0;j--,k++)
			b[k]=a[i][j];
			merge();
			for(j=3,k=0;j>=0;j--,k++)
			a[i][j]=b[k];
		}
	}
	else if(op==3)
	{
		for(j=0;j<4;j++)
		{
			for(i=3,k=0;i>=0;i--,k++)
			b[k]=a[i][j];
			merge();
			for(i=3,k=0;i>=0;i--,k++)
			a[i][j]=b[k];
		}
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}