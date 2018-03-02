#include<stdio.h>
void print(int a[4][4])
{
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	printf("%d",a[i][j]);
}
int main()
{
	int a[4][4];
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	a[i][j]=i+j;
	print(a);
	return 0;
}
