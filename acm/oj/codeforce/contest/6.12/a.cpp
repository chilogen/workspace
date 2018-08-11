#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n,k,arya,i,j;
	cin>>n>>k;
	arya=0;
	for(i=0;i<n;i++)
	{
		cin>>j;
		arya+=j;
		if(arya>8)
		{
			arya-=8;
			k-=8;
			if(k>0)	continue;
			break;
		}
		k-=arya;
		arya=0;
		if(k>0)	continue;
		break;
	}
	if(k>0)	cout<<-1<<endl;
	else cout<<i+1<<endl;
	return 0;
}