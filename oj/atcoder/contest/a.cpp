#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	long int n,i,j,k,l;
	scanf("%ld%ld%ld",&n,&i,&j);
	if(i>j)	{printf("0");	return 0;}
	if(n==1&&i!=j)	{printf("0");	return 0;}
	k=(n-1)*i+j;
	l=(n-1)*j+i;
	printf("%ld",l-k+1);
	return 0;
}