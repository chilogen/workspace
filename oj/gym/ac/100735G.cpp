#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s[100010];
	int i,j,k,len;
	scanf("%s",s);
	len=strlen(s);
	j=0;k=0;
	for(i=0;i<len;i++)
	{
		if(s[i]=='0')	j++;
		else k++;
	}
	cout<<min(j,k)<<endl;
	return 0;
}