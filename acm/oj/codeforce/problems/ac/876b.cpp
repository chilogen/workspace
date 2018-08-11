//(x-y)%m==0 equart to x%m-y%m==0
//so divide number base on modular m
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100010],b[100010];
int main()
{
	LL n,k,m,i,j,l;
	cin>>n>>k>>m;
	for(i=0;i<n;i++)	cin>>a[i];
	memset(b,0,sizeof(b));
	for(i=0,j=-1;i<n;i++)
	{
		b[a[i]%m]++;
		if(b[a[i]%m]>=k)
		{
			j=a[i]%m;
			break;
		}
	}
	if(j!=-1)
	{
		cout<<"Yes"<<endl;
		for(i=0,l=0;i<n&&l<k;i++)
		{
			if(a[i]%m==j)
			{
				cout<<a[i]<<" ";
				l++;
			}
		}
	}
	else
		cout<<"No"<<endl;
	return 0;
}