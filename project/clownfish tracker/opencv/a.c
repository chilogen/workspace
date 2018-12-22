#define A 100
#define B 10
#define C(a,b) a+ \
	b
#include <stdio.h>
int main()
{
	
	printf("%d",C(2,3));
	return 0;
}
