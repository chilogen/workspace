#include <stdio.h>
int lcd(int a,int b)
{
	if(a<b)
	{
		a=a^b;	b=a^b; a=a^b;
	}
	if(a%b==0) return b;
	a=a-b*(a/b);
	return lcd(b,a);
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",lcd(a,b));
	return 0;

}