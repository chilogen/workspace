#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s,q;
	long long t=0,i;
	cin>>i;
	getline(cin,s);
	while(getline(cin,s))
	{
		t++;
		if(s=="END OF CASE")
		{
			t=0;
			q="";
			continue;
		}
		for(i=0;i<s.length();i++)
		{
			if(s[i]==';')	
			{
				cout<<t<<": "<<q<<';'<<endl;
				q="";
			}
			else q+=s[i];
		}
	}
	return 0;
}