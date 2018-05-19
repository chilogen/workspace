#include <bits/stdc++.h>
using namespace std;
#define reset(a,b) memset(a,b,sizeof(a))

int s[110],sg[10010],nex[10010];
void getsg()
{
	reset(sg,0);
	int i,j,k,l;
	for(i=1;i<=10000;i++)
	{
		reset(nex,0);
		for(j=1;j<=10000&&s[j]<=i;j++)
			nex[i-s[j]]=1;
		for(j=0;j<=10000;j++)
		{
			if(!nex[j])
			{
				sg[i]=j;
				break;
			}
		}
	}
}
int main()
{
	int k,m,i,j,l,h;
	cin>>k;
	for(i=0;i<k;i++)	cin>>s[i];
	cin>>m;
	getsg();
	while(m--)
	{
		cin>>j;
		l=0;
		for(i=0;i<j;i++)
		{
			cin>>h;
			l^=sg[h];
		}
		if(l==0)	cout<<"win!"<<endl;
		else cout<<"lose!"<<endl;
	}
	return 0;
}