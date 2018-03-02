#include <bits/stdc++.h>
using namespace std;
#define reset(a,b)	memset(a,b,sizeof(a))
typedef long long LL;
int main()
{
	freopen("bulls.in","r",stdin);
	freopen("bulls.out","w",stdout);
	LL bull=0,cow=0,i,j,k;
	string s1,s2;
	set<LL>s;
	cin>>s1>>s2;
	for(i=0;i<s1.length();i++)
	{
		s.insert(s1[i]-'0');
	}
	for(i=0;i<s2.length();i++)
	{
		j=s2[i]-'0';
		if(s.count(j)!=0)
		{
			if(s1[i]==s2[i])
				bull++;
			else cow++;
		}
	}
	cout<<bull<<" "<<cow<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}