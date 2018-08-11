#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n,k,i,j,x;
	string o;
	LL s,d;
	cin>>n>>k;
	s=1;	d=k;
	for(i=0;i<n;i++)
	{
		cin>>x>>o;
		if(o=="SAFE")
		{
			if(x>s)	s=x;
		}
		else if(o=="BROKEN")
		{
			if(x<d)	d=x;
		}
	}
	cout<<s+1<<" "<<d-1<<endl;
	return 0;
}