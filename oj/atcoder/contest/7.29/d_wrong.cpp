#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	int a[60],i,j,k,l,n;
	cin>>k;
	n=4;
	cout<<n<<endl;
	for(i=0;i<n;i++)	a[i]=n-1;
	for(i=0;i<k;i++)
	{
		j=i%n;
		for(l=0;l<n;l++)
		{
			if(l==j)	a[l]+=n;
			else a[l]-=1;
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}