#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char a[100][100];
int n,m,sx,sy;
map<int,char>ma;
bool ok(string s)
{
	int x=sx,y=sy;
	int i,len=s.length();
	for(i=0;i<len;i++)
	{
		switch (ma[s[i]-'0'])
		{
			case '0':
			{
				x--;
				if(x<0)	return false;
				if(a[x][y]=='#')	return false;
				if(a[x][y]=='E')	
					return true;
				break;
			}
			case '1':
			{
				y--;
				if(y<0)	return false;
				if(a[x][y]=='#')	return false;
				if(a[x][y]=='E')	
					return true;
				break;
			}
			case '2':
			{
				x++;
				if(x==n)	return false;
				if(a[x][y]=='#')	return false;
				if(a[x][y]=='E')	
					return true;
				break;
			}
			case '3':
			{
				y++;
				if(y==m)	return false;
				if(a[x][y]=='#')	return false;
				if(a[x][y]=='E')	
					return true;
				break;
			}
		}
	}
	return false;
}
int main()
{
	int i,j,k=0;
	string s;
	char c[4]={'0','1','2','3'};
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		a[66][66]=getchar();
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='S')
			{
				sx=i;sy=j;
			}
		}
	}
	cin>>s;
	do
	{
		for(i=0;i<4;i++)	ma[i]=c[i];
		if(ok(s))	
			k++;
	}while(next_permutation(c,c+4));
	cout<<k<<endl;
	return 0;
}