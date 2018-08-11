#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long k,n,m;
	cin>>k;
	while(k--)
	{
		cin>>n>>m;
		if(n*m%6!=0||n==1||m==1)
			cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}