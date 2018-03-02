#include<stdio.h>
struct abc
{
	int a;
	int b;
}c[2];
int main()
{
	void *p;
	c[0].a=1;c[0].b=2;c[1].a=3;c[2].b=4;
	p=&c[0];
	printf("%d\n",*(int *)(p+1*sizeof(struct abc)));
	return 0;
}
