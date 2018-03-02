#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL b1=0,b2=0,one;
LL n;
bool f=false;
int getb2(int x,string s)
{
	int a[26]={0},i,j,len=s.length();
	for(i=0;i<len;i++)
	{
		j=s[i]-'a';
		a[j]=1;
	}
	for(i=0;i<26;i++)
	{
		if(a[i])	x=x^(1<<i);
	}
	return x;
}
bool check(int x)
{
	int m=0;
	while(x)
	{
		if(x&1)	m++;
		x=x>>1;
	}
	if(m==1)	f=1;
}
int main()
{
	string s;
	char c;
	LL i,j,k,ans=0;
	cin>>n;
	for(i=0;i<26;i++)	b1=b1^(1<<i);
	one=b1;
	for(i=0;i<n;i++)
	{
		c=getchar();
		c=getchar();
		cin>>s;
		switch(c)
		{
			case '!':
			{
				if(f)
				{
					ans++;
					break;
				}
				b2=0;
				b2=getb2(b2,s);
				b1=b2&b1;
				check(b1);
				break;
			}
			case '.':
			{
				b2=one;
				b2=getb2(b2,s);
				b1=b2&b1;
				check(b1);
				break;
			}
			case '?':
			{
				if(f)
				{
					ans++;
					break;
				}
				b2=one;
				b2=getb2(b2,s);
				b1=b2&b1;
				check(b1);
				break;
			}
		}
	}
	if(ans!=0)	cout<<ans-1<<endl;
	else cout<<ans<<endl;
	return 0;
}