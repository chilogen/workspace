#include <bits/stdc++.h>
using namespace std;
int main()
{
	char a[30],b[30],c[1500];
	int p1[30],p2[30];
	int i,j,k,l;
	scanf("%s%s%s",a,b,c);
	for(i=0;i<26;i++)
	{
		p1[a[i]-'a']=i;
		p2[b[i]-'a']=i;
	}
	for(i=0;i<strlen(c);i++)
	{
		if(c[i]<='z'&&c[i]>='a')
		{
			j=c[i]-'a';
			k=p1[j];
			for(l=0;l<26;l++)
			{
				if(p2[l]==k)	{cout<<(char)('a'+l);break;}
			}
		}
		else if(c[i]<='Z'&&c[i]>='A')
		{
			j=c[i]-'A';
			k=p1[j];
			for(l=0;l<26;l++)
			{
				if(p2[l]==k)	{cout<<(char)('A'+l);break;}
			}
		}
		else cout<<c[i];
	}
	return 0;
}