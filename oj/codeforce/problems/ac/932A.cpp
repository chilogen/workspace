#include <bits/stdc++.h>
using namespace std;
int main(){\
	string s;
	int len,i;
	cin>>s;
	len=s.length();
	for(i=0;i<len;i++)cout<<s[i];
	for(i=len-1;i>=0;i--)cout<<s[i];
	cout<<endl;
	return 0;
}