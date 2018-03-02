#include <iostream>
using namespace std;
int main()
{
	char s[50];
	int a[50]={0};
	char c;
	c=getchar();
	int i,j,k=0;
	while(c!='\n')
	{
		s[k]=c;
		k++;
		if(k==50)	break;
		c=getchar();
	}
	for(i=1;i<k;i++)
	{
		if(s[i]-'0'>=0&&s[i]-'9'<=0)	continue;
		if(s[i]-'a'>=0&&s[i]-'z'<=0)	continue;
		if(s[i]-'A'>=0&&s[i]-'Z'<=0)	continue;
		if(s[i]==s[i-1])	a[i]=1;
	}
	for(i=0;i<k;i++)
	{
		if(a[i]==0)	cout<<s[i];
	}
	return 0;
}