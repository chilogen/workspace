#include <iostream>
#include <cstring>
#define INF 9999
using namespace std;
void minmax(int s[])
{
	int max=-INF,min=INF,ave;
	int i,j,k;
	for(i=0;i<10;i++)
	{
		if(s[i]>max) max=s[i];
		if(s[i]<min) min=s[i];
		ave+=s[i];
	}
	ave/=i;
	cout<<min<<","<<max<<","<<ave<<endl;
}
int main()
{
	int a[1000],i=0;
	memset(a,-1,sizeof(a));
	for(i=0;i<10;i++)
		cin>>a[i];
	minmax(a);
	return 0;
}