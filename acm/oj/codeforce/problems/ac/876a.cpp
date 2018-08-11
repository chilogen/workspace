#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	if(n==1)	cout<<0<<endl;
	else if(a==min(a,min(b,c))||b==min(a,min(b,c)))
		cout<<min(a,b)*(n-1)<<endl;
	else 	cout<<min(a,b)+c*(n-2);
	return 0;
}