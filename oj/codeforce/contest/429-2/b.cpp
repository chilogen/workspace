#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n,count=0,i,j,k;
	cin>>n;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&j);
		if(j%2)	count++;
	}
	if(count==0)	cout<<"Second"<<endl;
	else cout<<"First"<<endl;
	return 0;
}