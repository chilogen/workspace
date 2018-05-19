#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[6],b[6],day[6],inv[6],m[6],M;
void inver(LL a,LL b,LL &s,LL &t)
{
	if(b==0)
	{
		s=1;
		t=0;
		return ;
	}
	inver(b,a%b,t,s);
	t=t-s*(a/b);
}
int main()
{
	int n,i,j,k;
	LL x=0,c,d;
	M=1;
	for(i=0;i<6;i++)
	{
		cin>>a[i];
		M*=a[i];
	}
	for(i=0;i<6;i++)	
	{
		cin>>day[i];
		b[i]=day[i]%a[i];
	}
	for(i=0;i<6;i++)
	{
		m[i]=M/a[i];
		inver(m[i],a[i],c,d);
		inv[i]=c;
		inv[i]=(inv[i]+a[i])%a[i];
		x=(x+b[i]*inv[i]*m[i])%M;
	}
	j=0;
	for(i=0;i<6;i++)
		if(j<day[i])	j=day[i];
	if(x<j)	x=x+((j-x-1)/M+1)*M;
	cout<<x<<endl;
	return 0;
}