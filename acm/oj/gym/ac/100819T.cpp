#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[3],b[3];
bool check(LL i,LL j)
{
	LL x,y,z,m;
	z=a[i]*a[i];
	x=y=0;
	for(m=0;m<3;m++)
	{
		if(m!=i)	x+=a[m]*a[m];
	}
	if(x==z)	return true;
	else return false;
}
int main()
{
	LL i,j,k;
	map<LL,LL> m;
	for(i=0;i<3;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<3;i++)
		cin>>b[i];
	for(i=0;i<3;i++)	m[a[i]]=m[b[i]]=0;
	for(i=0;i<3;i++)	{m[a[i]]++;	m[b[i]]++;}
	for(i=0;i<3;i++)
	{
		if(m[a[i]]!=2||m[b[i]]!=2)	{puts("NO");	return 0;}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(a[i]==b[j])
			{
				if(check(i,j)){puts("YES");	return 0;}
			}
		}
	}
	puts("NO");
	return 0;
}