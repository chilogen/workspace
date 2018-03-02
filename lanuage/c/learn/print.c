#include<stdio.h>
int main()
{
	FILE *f=fopen("a.t","wr");
	int a=5;
	fprintf(f,"%d\n",a);
	printf("%d\n",a);
	fclose(f);
	return 0;
}
