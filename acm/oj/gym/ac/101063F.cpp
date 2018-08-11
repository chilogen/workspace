#include <iostream>
using namespace std;
int main()
{
	int n,k,sum;
	cin>>n>>k;
	n++;
	if(n==k)
	{
		cout<<"yes";
		return 0;
	}
	if(n>k&&n%k==0)
	{
		cout<<"yes";
		return 0;
	}
	cout<<"no";
	return 0;
}