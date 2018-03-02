#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand((unsigned)time(NULL));
	printf("%d  %d\n",rand(),rand());
	return 0;
}
