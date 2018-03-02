#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n,m,b,i,j,k,l;
	LL a[2][101][101];
	cin>>n>>m>>b;
	swap(n,m);
	for(i=0;i<n;i++)	for(j=0;j<m;j++)	cin>>a[0][i][j];
	k=1;
	while(b--)
	{
		k=!k;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				l=a[k][(i+n-1)%n][(j+m-1)%m]+a[k][(i+n-1)%n][j]+a[k][(i+n-1)%n][(j+1)%m]+ \
				  a[k][i][(j+m-1)%m]+a[k][i][j]+a[k][i][(j+1)%m]+ \
				  a[k][(i+1)%n][(j+m-1)%m]+a[k][(i+1)%n][j]+a[k][(i+1)%n][(j+1)%m];
				a[!k][i][j]=l;
			}
		}
	}
	k=!k;
	set<LL>s;
	for(i=0;i<n;i++)	for(j=0;j<m;j++)	s.insert(a[k][i][j]);
	cout<<s.size()<<endl;
	return 0;
}