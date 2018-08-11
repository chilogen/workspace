#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int src[70],dst[70];
int main()
{
	int kase=0,i,j,k,n;
	long long res;
	whlile(1)
	{
		cin>>n;
		if(n==0)	break;
		kase++;	res=0;
		for(i=1;i<=n;i++)	cin>>src[i];
		for(i=1;i<=n;i++)	cin>>dst[i];
		for(k=n;k>0;k--)
			if(src[k]!=dst[k])	break;
		for(;k>0;k--)
			res+=f()
	}
}