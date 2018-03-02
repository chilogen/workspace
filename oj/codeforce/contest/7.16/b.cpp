#include <bits/stdc++.h>
using namespace std;
char a[10][11];
int hori(int x,int y,int c)
{
	int  ans=0;
	while(x>=0&&x<10)
	{
		x+=c;
		if(a[x][y]=='X')	ans++;
		else break;
	}
	return ans;
}
int vet(int x,int y,int c)
{
	int  ans=0;
	while(y>=0&&y<10)
	{
		y+=c;
		if(a[x][y]=='X')	ans++;
		else break;
	}
	return ans;
}
int dig1(int x,int y,int c)
{
	int  ans=0;
	while(x>=0&&x<10&&y>=0&&y<10)
	{
		x+=c;	y+=c;
		if(a[x][y]=='X')	ans++;
		else break;
	}
	return ans;
}
int dig2(int x,int y,int c)
{
	int  ans=0;
	while(x>=0&&x<10&&y>=0&&y<10)
	{
		x+=c;	y-=c;
		if(a[x][y]=='X')	ans++;
		else break;
	}
	return ans;
}
int main()
{
	int i,j,k,l;
	for(i=0;i<10;i++)	
		scanf("%s",a[i]);
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(a[i][j]!='.')	continue;
			if(hori(i,j,1)+hori(i,j,-1)>=4)
			{
				puts("YES");
				return 0;
			}
			if(vet(i,j,1)+vet(i,j,-1)>=4)
			{
				puts("YES");
				return 0;
			}
			if(dig1(i,j,1)+dig1(i,j,-1)>=4)
			{
				puts("YES");
				return 0;
			}
			if(dig2(i,j,1)+dig2(i,j,-1)>=4)
			{
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}