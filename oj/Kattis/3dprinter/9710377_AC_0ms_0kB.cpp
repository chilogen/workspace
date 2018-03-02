#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n,t,i,tmp,mac=1;
	cin>>n;
	t=n;
	for(i=1;i<n;i++)
	{
		mac=mac*2;
		if(mac>=n)	break;
		if(n%mac==0)	tmp=n/mac;
		else tmp=n/mac+1;
		tmp=tmp+i;
		if(t>tmp)	t=tmp;
	}
	cout<<t<<endl;
}