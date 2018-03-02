#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	string s;
	LL a[26],com=0,i,j,k,l;
	memset(a,0,sizeof(a));
	cin>>s;
	for(i=0;i<s.length();i++)
	{
		if(a[s[i]-'a']==0)	com++;
		a[s[i]-'a']++;
	}
	LL ans=0;
	while(com>2)
	{
		j=-1;	k=1111;
		for(i=0;i<26;i++)
		{
			if(a[i]<k&&a[i]!=0)
			{
				k=a[i];	j=i;
			}
		}
		com-=1;
		a[j]=0;
		ans+=k;
	}
	cout<<ans<<endl;
	return 0;
}