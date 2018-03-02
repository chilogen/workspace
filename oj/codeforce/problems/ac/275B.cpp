#include <bits/stdc++.h>
using namespace std;
char c[60][60];
int n,m;
pair<int,int>p[3000];
bool isblack(int sx,int ex,int sy,int ey)
{
	int px,py;
	if(ex==sx)	px=1;
	else px=(ex-sx)/abs(ex-sx);
	if(ey==sy)	py=1;
	else py=(ey-sy)/abs(ey-sy);
	int i,j;
	for(i=sx;i<=ex*px;i+=px)
		for(j=sy;j<=ey*py;j+=py)
			if(c[i][j]=='W')	return false;
	return true;
}
inline bool check(int i,int j)
{
	return (isblack(p[i].first,p[j].first,p[i].second,p[i].second)&& \
			isblack(p[j].first,p[j].first,p[i].second,p[j].second))|| \
		   (isblack(p[i].first,p[i].first,p[i].second,p[j].second)&& \
		   	isblack(p[i].first,p[j].first,p[j].second,p[j].second));
}
int main()
{
	cin>>n>>m;
	int i,j,k;
	string s;
	for(i=0,k=0;i<n;i++)
	{
		cin>>s;
		for(j=0;j<m;j++)
		{
			c[i][j]=s[j];
			if(s[j]=='B')	p[k++]=make_pair(i,j);
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
			if(!check(i,j))	j=k+1;
		if(j>k)	i=k+1;
	}
	if(i>k)	cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}