//1--对角线分子加分母相等，等于n(行数)+1
//2--偶数行分子递增，奇数行分子递减
#include<stdio.h>
int main()
{
	int i,n,j;
	scanf("%d",&n);
	for(i=0;;i++)
	{
		j=i+1;
		if((int)(1+i)*i/2.0<=n&&(int)(1+j)*j/2.0>=n)
		break;
	}
	n-=(int)(1+i)*i/2.0;
	printf("%d/%d",j%2==0?n:j+1-n,j%2==0?j+1-n:n);
	return 0;
}
