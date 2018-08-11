#include <bits/stdc++.h>
using namespace std;
int b[600];
int main()
{
	int p,n,i,j,k,len;
	char c;
	string s;
	cin>>p;
	while(p--)
	{
		cin>>k;
		c=getchar();
		s="";
		getline(cin,s);
		len=s.length();
		cin>>n;
		for(i=0;i<n;i++)	cin>>b[i];
		cout<<k<<" ";
		for(i=0,j=0;i<n;i++)
		{
			j+=b[i];	j=(j+len)%len;
			cout<<s[j];
		}
		cout<<endl;
	}
	return 0;
}