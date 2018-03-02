/*
	This program use to show the diffrent between sign and unsign type
*/
#include<stdio.h>
int main()
{
	int s_int;
	unsigned int u_int;
	unsigned long u_long;
	unsigned char u_char;
	scanf("%d%ld%c",&s_int,&u_long,&u_char);
	u_int=(unsigned int)s_int;
	printf("signed int:%d\n",s_int);
	printf("unsigned int:%u\n",u_int);
	printf("unsigned long:%lu\n",u_long);
	printf("unsigned char:%u\n",u_char);
	return 0;
}
