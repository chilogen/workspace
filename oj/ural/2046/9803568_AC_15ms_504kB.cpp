#include <bits/stdc++.h>
using namespace std;
#define reset(a,b)	memset(a,b,sizeof(a))
struct cell
{
	char name[6][15];
	int now,ma;
}c[5][5];
int main()
{
	string s1="+----------+----------+----------+";
	string s2="          |";
	string s,date;
	int n,remain[5];
	int i,j,k,l,o,x,y;
	cin>>n;
	reset(remain,0);
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=3;j++)
		{
			reset(c[i][j].name,0);
			c[i][j].ma=-1;c[i][j].now=0;
		}
	}
	for(i=1;i<=n;i++)
	{
		getline(cin,s);
		getline(cin,s);
		cin>>date>>x;
		if(date=="Tuesday")	y=1;
		else if(date=="Thursday")	y=2;
		else if(date=="Saturday")	y=3;
		c[x][y].ma++;
		for(j=0,k=0;j<s.length();j++,k++)
		{
			if(s[j]==' ')
			{
				c[x][y].ma++;
				k=-1;
				continue;
			}
			c[x][y].name[c[x][y].ma][k]=s[j];
		}
		remain[x]+=(c[x][y].ma+1);
	}
	cout<<s1<<endl;
	for(i=1;i<=4;)
	{
		cout<<"|";
		for(j=1;j<=3;j++)
		{
			cell &a=c[i][j];
			if(a.now<=a.ma)
			{
				k=10;
				while(a.now<=a.ma)
				{
					l=strlen(a.name[a.now]);
					if(k-l>=0)
						printf("%s",a.name[a.now]);
					else break;
					k-=strlen(a.name[a.now]);
					remain[i]--;
					if(k>0)
					{
						k--;
						cout<<" ";
					}
					a.now++;
				}
				while(k>0){cout<<" ";	k--;}
				cout<<"|";
			}
			else	cout<<s2;
		}
		if(remain[i]==0)	
		{
			i++;
			cout<<endl<<s1<<endl;
		}
		else 
			cout<<endl;
	}
	return 0;
}