#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	string s;
	cin>>s;
	int i,j,k=0,len=s.length();
	for(i=0;i<len;i++)
	{
		j=s[i]-'0';
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')	k++;
		else if(j>=0&&j<=9)
		{
			if(j%2==1)	k++;
		}
	}
	cout<<k<<endl;
	return 0;
}