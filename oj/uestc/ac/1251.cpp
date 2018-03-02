#include <bits/stdc++.h>
using namespace std;
int main()
{
	int pass[2][110];
	int t,n,s,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		memset(pass,0,sizeof(pass));
		if(n==1&&s==0)
		{
			cout<<0<<" "<<0<<endl;
			continue;
		}
		if(s==0)
		{
			cout<<-1<<" "<<-1<<endl;
			continue;
		}
		j=s;
		s--;
		pass[0][1]=1;
		for(i=n;i>=2&&s!=0;i--)
		{
			if(s>9)
			{
				pass[0][i]=9;
				s-=9;
			}
			else
			{
				pass[0][i]=s;
				s=0;
			}
		}
		if(s>8)
		{
			cout<<-1<<" "<<-1<<endl;
			continue;
		}
		pass[0][1]+=s;
		for(i=1;i<=n&&j!=0;i++)
		{
			if(j>9)
			{
				pass[1][i]=9;
				j-=9;
			}
			else 
			{
				pass[1][i]=j;
				j=0;
			}
		}
		if(j!=0)
		{
			cout<<-1<<" "<<-1<<endl;
			continue;
		}
		for(i=1;i<=n;i++)	cout<<pass[0][i];
		cout<<" ";
		for(i=1;i<=n;i++)	cout<<pass[1][i];
		cout<<endl;
	}
}