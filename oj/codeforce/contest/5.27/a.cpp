#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	freopen("abc","r",stdin);
	double a,b;
	long int c,d;
	scanf("%lf%lf",&a,&b);
	if(a==b)	{printf("Valera");	return 0;}
	c=(long int)sqrt(a);
	d=(long int)sqrt(b);
	if(c<=d)	printf("Vladik");
	else printf("Valera");
	fclose(stdin);
	return 0;
}