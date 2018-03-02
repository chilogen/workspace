#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int n,i,j,k;
	cin>>s;
	k=0;
	for(i=0;i<s.length();)
	{
		if(s[i]!='P')	k++;
		i++;
		if(s[i]!='E')	k++;
		i++;
		if(s[i]!='R')	k++;
		i++;
	}
	cout<<k<<endl;
	return 0;
}