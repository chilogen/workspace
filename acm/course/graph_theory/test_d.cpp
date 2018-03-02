#include <cstdio>
using namespace std;
int main()
{
	int n=1000,i,j,k;
	freopen("abc","w",stdout);
	printf("%d\n",n);
	for(i=0;n>0&&i<26;i++)
		for(j=0;n>0&&j<26;j++)
			for(k=0;n>0&&k<26;k++)
			{
				printf("%c%c%c\n",i+'a',j+'a',k+'a');
				n--;
			}
	fclose(stdout);
	return 0;
}