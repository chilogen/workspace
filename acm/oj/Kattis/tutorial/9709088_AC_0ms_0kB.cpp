#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,t;
bool p(LL i)
{
	LL ans=1,a=2;
	while(i)
	{
		if(i&1)
		{
			ans=ans*a;
			if(ans>m)	return true;
		}
		i=i>>1;
		a=a*a;
	}
	return false;
}
int main()
{
	LL i,j,l,ti;
	LL k[20];
	k[0]=1;
	for(i=1;i<16;i++)
	{
		k[i]=k[i-1]*i;
	}
	cin>>m>>n>>t;
	ti=1;
	if(t==1)
	{
		if(n>15){puts("TLE");	return 0;}
		if(k[n]>m){puts("TLE");	return 0;}
	}
	else if(t==2)
	{
		if(p(n)){puts("TLE");	return 0;}
	}
	else if(t==3)
	{
		for(i=0;i<4;i++)
		{
			ti=ti*n;
			if(ti>m){puts("TLE");	return 0;}
		}
	}
	else if(t==4)
	{
		for(i=0;i<3;i++)
		{
			ti=ti*n;
			if(ti>m){puts("TLE");	return 0;}
		}

	}
	else if(t==5)
	{
		if(n*n>m){puts("TLE");	return 0;}
	}
	else if(t==6)
	{
		if(n*(log(n)/log(2))>m)
		{
			puts("TLE");
			return 0;
		}
	}
	else if(t==7)
	{
		if(n>m){puts("TLE");	return 0;}
	}
	puts("AC");
	return 0;
}