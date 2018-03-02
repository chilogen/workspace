#include<stdio.h>
int main()
{
	int num=1,loop;
	for(loop=0;loop<9;loop++)
	{
		num=(num+1)*2;
		printf("%d,",num);
	}
	printf("%d",num);
	return 0;
}
