#include <bits/stdc++.h>
using namespace std;
#define reset(a,b)	memset(a,b,sizeof(a))
typedef long long LL;
char c;
bool good[30];
int main()
{
	string a,b;
	LL len,len1,i,j,k,n;
	reset(good,0);
	getline(cin,b);
	len1=b.length();;
	for(i=0;i<len1;i++)
		good[b[i]-'a']=true;
	getline(cin,a);
	len=a.length();
	for(i=0;i<len;i++)
	{
		if(a[i]=='*')
		{
			good[29]=true;
			break;
		}
	}
	cin>>n;getchar();
	while(n--)
	{
		b="";
		getline(cin,b);
		len1=b.length();
		if(good[29]==false&&len1!=len)
		{
			puts("NO");
			continue;
		}
		//if(a[len-1]=='*')	b=b+' ';
		for(i=0,j=0;i<len;)
		{
			if(i==len||j==len1)	
			{
				if(a[i]=='*')	i++;
				break;
			}
			if(a[i]==b[j])	{i++;j++;continue;}
			if(a[i]=='?'&&good[b[j]-'a']){i++;j++;continue;}
			if(a[i]=='*'&&!good[b[j]-'a']){j++;	continue;}
			if(a[i]=='*'&&good[b[j]-'a']){i++;	continue;}
			break;
		}
		if(i==len&&j==len1)	puts("YES");
		else puts("NO");
	}
	return 0;
}