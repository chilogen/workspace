#include "../include/BigInteger.h"
#include <bits/stdc++.h>
using namespace std;


int main()
{
	string ans,s1,s2,c;
	cin>>c;
	bool method=StringProcess(s1,s2,c);
	Integer a(s1),b(s2);
	if(method)	cout<<a-b<<endl;
	else cout<<a+b<<endl;
	return 0;
}
