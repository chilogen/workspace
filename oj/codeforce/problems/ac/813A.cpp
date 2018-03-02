#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[200],i,j,k;
	cin>>n;
	for(i=0;i<n;i++)	cin>>a[i];
	j=0;
	for(i=1;i<n;i++)
	{
		if(j==0)
		{
			if(a[i]>a[i-1])	continue;
			else if(a[i]==a[i-1])	{j=1;	continue;}
			else if(a[i]<a[i-1])	{j=2;	continue;}
			else
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		else if(j==1)
		{
			if(a[i]==a[i-1])	continue;
			else if(a[i]<a[i-1])	{j=2;	continue;}
			else
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		else if(j==2)
		{
			if(a[i]>=a[i-1])
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}