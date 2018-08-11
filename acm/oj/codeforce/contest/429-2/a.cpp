#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,i;
	string s;
	bool j=true;
	int num[27]={0};
	cin>>n>>k>>s;
	for(i=0;i<s.length();i++)
	{
		num[s[i]-'a']++;
	}
	for(i=0;i<26;i++)
	{
		if(num[i]>k)
		{
			cout<<"NO"<<endl;
			return 0;
		}	
	}
	cout<<"YES"<<endl;
	return 0;
}