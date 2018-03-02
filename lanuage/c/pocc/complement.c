#include<stdio.h>
int main()
{
	printf("Enter two unsigned num A and B the return the result of A-B\n");
	unsigned int a,b;
	scanf("%u%u",&a,&b);
	b=~b+1; //get the complement of b
	printf("print as integer:A+B=%d\n",a+b);
	printf("print as unsigned:A+B=%u\n",a+b);
	return 0;
}
