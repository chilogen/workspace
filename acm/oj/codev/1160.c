//以 1 为中心点建立直角坐标系，自左向右，自上而下增长矩阵
#include<stdio.h>
int main()
{
	int n,l,i,j,signal,sum;
	int a[100][100]={0};
	scanf("%d",&n);
	l=n/2;
	for(i=0;i<=l;i++)
	a[i][i]=4*(l-i)*(l-i)+1;
	for(i=l+1;i<n;i++)
	a[i][i]=(2*(i-l)+1)*(2*(i-l)+1);
	for(i=l;i>=-l;i--)
	{
		for(j=-l;j<=l;j++)
		{
			if(i+j==0) continue;
			if(i+j>0) signal=-1;
			else signal=1;
			if((i+j)*(i-j)>0)
			{
				a[l-i][j+l]=a[l-i][j+l-1]+signal;
			}
			else if((i+j)*(i-j)<0)
			{
				a[l-i][j+l]=a[l-i-1][j+l]+signal;
			}
			else if((i+j)*(i-j)==0)
			{
				if(i>0)  a[l-i][j+l]=a[l-i][j+l-1]+signal;
				else  a[l-i][j+l]=a[l-i-1][j+l]+signal;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	sum=0;
	for(i=0;i<n;i++)
	{
		sum+=a[i][i];
		sum+=a[i][n-1-i];
	}
	sum-=a[l][l];
	printf("%d\n",sum);
	return 0;
}
