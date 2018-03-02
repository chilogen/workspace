#include<stdio.h>
#include<stdlib.h>
int *new()
{
	int *p=(int *)malloc(sizeof(int));
	return p;
}
int main()
{
	int *p=new();
	scanf("%d",p);
	printf("%d",*p);
	return 0;
}
