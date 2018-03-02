#include<stdio.h>
#include<stdlib.h>
int main()
{
	system("stty -echo");
	char c;
	c=getchar();
	if(c=='a') printf("ok\n");
	system("stty echo");
	return 0;
}
