#include <iostream>
#include <map>
using namespace std;
using namespace std;

int main()
{
	map <int,int> m;
	int a[100],b[100],d[100];
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)	cin>>a[i];
	for(i=0;i<n;i++)	{cin>>b[i]; m[b[i]]=i;}
	for(i=0;i<n;i++)
	{
		d[i]=m[a[i]];
		cout<<d[i]<<" ";
	}
	return 0;
}