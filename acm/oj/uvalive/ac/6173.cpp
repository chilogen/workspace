#include <bits/stdc++.h>
using namespace std;
char a[10000100];
int main()
{
	int t,b,i,j,k,l,len;
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&k,&b);
		scanf("%s",a);
		len=strlen(a);
		l=0;
		for(i=0;i<len;i++)
		{
			j=l*b+(a[i]-'0');
			l=j%(b-1);
		}
		cout<<k<<" "<<(l+b)%b<<endl;
	}
	return 0;
}