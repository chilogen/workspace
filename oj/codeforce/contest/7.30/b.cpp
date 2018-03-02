#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL s[30],e[30],T[1000010];
int main()
{
	LL n,k,i,j,l;
	string m;
	cin>>n>>k>>m;
	memset(s,-1,sizeof(s));
	memset(e,-1,sizeof(e));
	memset(T,0,sizeof(T));
	for(i=0;i<n;i++)
	{
		j=m[i]-'A';
		if(s[j]!=-1)	e[j]=i+1;
		else {s[j]=i;	e[j]=i+1;}
	}
	for(i=0;i<26;i++)
	{
		if(s[i]==-1)	continue;
		T[s[i]]--;
		T[e[i]]++;
	}
	for(i=0;i<n;i++)
	{
		k+=T[i];
		if(k<0)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}