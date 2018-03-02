#include <bits/stdc++.h>
using namespace std;
const int maxn=101;
int m[maxn][maxn];
int main()
{
	int n,q,i,j,k,l;
	cin>>n;
	for(i=0;i<=100;i++)
		for(j=0;j<=100;j++)
		{
			if(i==j)	m[i][j]=0;
			else m[i][j]=100000;
		}
	for(i=1;i<=n;i++)
	{
		cin>>j>>k>>l;
		m[j][k]=m[k][j]=l;
	}
	for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		m[i][j]=min(m[i][k]+m[k][j],m[i][j]);
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		cout<<m[a][b]<<endl;
	}
	return 0;
}