#include <iostream>
#include <string>
using namespace std;
int main()
{
	char s[2][500],c;
	int i=0,k=0;
	c=getchar();
	while(c!='\n')
	{
		s[i][k]=c;
		k++;
		c=getchar();
	}
	i++;	k=0;
	c=getchar();
	while(c!='\n')
	{
		s[i][k]=c;
		k++;
		c=getchar();
	}
	for(i=1;i<k;i++)
	{
		if(s[0][i]!=s[1][i])	break;
	}
	if(i!=k)	cout<<"unequal";
	else cout<<"equal";
	return 0;
}