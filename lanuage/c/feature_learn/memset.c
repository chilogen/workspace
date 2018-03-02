#include<stdio.h>
#include<string.h>
typedef struct
{
	int a,b;
}t;
t a[10];
int b[10];
int main()
{
	printf("Before use memset\nstrucr:\n");
	for(int i=0;i<10;i++)
	{
		printf("[%d] %d %d\n",i,a[i].a,a[i].b);
	}
	printf("Array:\n");
	for(int i=0;i<10;i++)
	{
		printf("[%d] %d\n",i,b[i]);
	}
	memset(&a[0].a,-1,sizeof(t)*10);
	memset(b,-1,sizeof(int)*10);
	printf("After use memset:\nstruct:\n");
	for(int i=0;i<10;i++)
	{
		printf("[%d] %d %d\n",i,a[i].a,a[i].b);
	}
	printf("Array:\n");
	for(int i=0;i<10;i++)
	{
		printf("[%d] %d\n",i,b[i]);
	}
	return 0;
}
