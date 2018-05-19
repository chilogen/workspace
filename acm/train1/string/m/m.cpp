#include <bits/stdc++.h>
using namespace std;
int m,n,ex,ey;
bool dfs(int sx,int sy,int t,char ma[6][6])
{
	int i,j,k,l;
	char c=ma[sx][sy];
	ma[sx][sy]='X';
	if(t==0&&sx==ex&&sy==ey)	return true;
	if(t==0) {ma[sx][sy]=c;		return false;}
	if(sx>0)
		if(ma[sx-1][sy]!='X')	if(dfs(sx-1,sy,t-1,ma))	return true;
	if(sy>0)
		if(ma[sx][sy-1]!='X')	if(dfs(sx,sy-1,t-1,ma))	return true;
	if(sx<n-1)
		if(ma[sx+1][sy]!='X')	if(dfs(sx+1,sy,t-1,ma))	return true;
	if(sy<m-1)
		if(ma[sx][sy+1]!='X')	if(dfs(sx,sy+1,t-1,ma))	return true;
	ma[sx][sy]=c;
	return false;
}
int main()
{
	int t,i,j,k,l,sx,sy;
	char ma[6][6];
	cin>>n>>m>>t;
	while(n||m||t)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				cin>>ma[i][j];
				if(ma[i][j]=='\n'||ma[i][j]=='\0'){j--;	continue;}
				if(ma[i][j]=='S')	{sx=i;	sy=j;}
				if(ma[i][j]=='D')	{ex=i;	ey=j;}
			}
		if((abs(sx-ex+sy-ey))%2!=t%2)	{cout<<"NO"<<endl;	cin>>n>>m>>t;	continue;}
		if(dfs(sx,sy,t,ma))	cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		cin>>n>>m>>t;
	}
	return 0;
}