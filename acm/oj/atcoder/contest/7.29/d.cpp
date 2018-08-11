#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL a[60],i,j,k,l,n;
	cin>>k;
	n=50;
	cout<<n<<endl;
	for(i=0;i<n;i++)	a[i]=n-1;
	j=k%n;	l=k/n;
	for(i=0;i<n;i++)
	{
		a[i]=a[i]+n*l;
		if(i<j)	a[i]+=n;
		if(j!=0&&i<j)	a[i]=a[i]-k+l+1;
		else a[i]=a[i]-k+l;
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}