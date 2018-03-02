#include <bits/stdc++.h>
using namespace std;
char a[110][110];
int main()
{
	int n,m,i,j,k,l,x1,x2,y1,y2;
	cin>>n>>m;
	for(i=0;i<n;i++)	scanf("%s",a[i]);
	x1=m-1;	x2=0;	y1=n-1;	y2=0;	k=0;
	for(i=0;i<n;i++)	for(j=0;j<m;j++)
	{
		if(a[i][j]=='B')
		{
			k++;
			if(j<x1)	x1=j;
			if(j>x2)	x2=j;
			if(i<y1)	y1=i;
			if(i>y2)	y2=i;
		}
	}
	if(y2-y1>m-1||x2-x1>n-1)	cout<<-1<<endl;
	else
	{
		l=max(y2-y1,x2-x1)+1;
		if(l<=0)	cout<<1<<endl;
		else	cout<<l*l-k<<endl;
	}
	return 0;
}