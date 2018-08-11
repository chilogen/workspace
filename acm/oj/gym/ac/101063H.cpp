#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAXNUM 500000
int main()
{
	int a[MAXNUM],positive[MAXNUM],impositive[MAXNUM],n,k,i,j,l,m;
	cin>>n>>k;
	LL ans=0;
	for(i=0;i<n;i++)	cin>>a[i];
	for(i=0;i<k;i++)
	{
		j=i;
		positive[i]=impositive[i]=0;
		while(j<n)
		{
			if(a[j]<0)	impositive[i]++;
			else if(a[j]>0)	positive[i]++;
			j=j+k;
		}
	}
	for(i=0,m=0,j=0,l=abs(positive[0]-impositive[0]);i<k;i++)
	{
		if(positive[i]<impositive[i])	{ans+=positive[i]; m++;}
		else ans+=impositive[i];
		if(abs(positive[i]-impositive[i])<l)
		{
			l=abs(positive[i]-impositive[i]);
			j=i;
		}
	}
	if(m%2)
	{
		ans=ans-min(positive[j],impositive[j])+max(positive[j],impositive[j]);
	}
	cout<<ans;
	return 0;
}