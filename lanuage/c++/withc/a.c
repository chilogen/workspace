#include<stdio.h>
#include"a.h"
extern char b[3];
int main()
{
	for(int i=0;i<3;i++)
	printf("%c ",b[i]);
	return 0;
}
