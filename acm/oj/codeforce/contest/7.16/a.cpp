#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	int a,i;
	cin>>a>>s;	a=0;
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='0')	{cout<<a;	a=0;}
		if(s[i]=='1')	a++;
	}
	cout<<a<<endl;
	return 0;
}