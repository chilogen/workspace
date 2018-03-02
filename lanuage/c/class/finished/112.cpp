#include <iostream>
#include <string>
using namespace std;
int main()
{
	char c;
	int i=0,j=0;
	c=getchar();
	while(c!='\n')
	{
		if(c-'0'>=0&&c-'9'<=0)	i++;
		else if(c-'a'>=0&&c-'z'<=0)	j++;
		else if(c-'A'>=0&&c-'Z'<=0)	j++;
		c=getchar();
	}
	cout<<"letters:"<<j<<","<<"digits:"<<i;
	return 0;
}