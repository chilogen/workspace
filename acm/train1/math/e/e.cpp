#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,a[14],i;
	cin>>n;
	if(n==1)	{cout<<"1";	return 0;}
	a[1]=1;
	for(i=2;i<=13;i++)
		a[i]=a[i-1]*i;
	cout<<a[n-1]*a[n];
	return 0;
}