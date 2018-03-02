//LTE  should use dancing links
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
#define reset(a,b)	memset(a,b,sizeof(a))
typedef long long LL;
char s[100];
bool constant[81];
int line[9],colume[9],cell[9],c[81],remain;
inline bool check(int i,int x)
{
	if(((line[x/9]&(1<<i))==0)&&((colume[x%9]&(1<<i))==0)&&((cell[c[x]]&(1<<i))==0))
		return true;
	return false;
}
inline void mark(int i,int x)
{
	line[x/9]|=(1<<i);
	colume[x%9]|=(1<<i);
	cell[c[x]]|=(1<<i);
}
inline void remark(int i,int x)
{
	line[x/9]^=(1<<i);
	colume[x%9]^=(1<<i);
	cell[c[x]]^=(1<<i);
}
inline void placec()
{
	int i,x,y;
	for(i=0;i<81;i++)
	{
		x=i/9;	y=i%9;
		if(x<=2&&y<=2)	c[i]=0;
		else if(x<=2&&y>2&&y<=5)	c[i]=1;
		else if(x<=2&&y>5)	c[i]=2;
		else if(x>2&&x<=5&&y<=2)	c[i]=3;
		else if(x>2&&x<=5&&y>2&&y<=5)	c[i]=4;
		else if(x>2&&x<=5&&y>2&&y>5)	c[i]=5;
		else if(x>5&&y<=2)	c[i]=6;
		else if(x>5&&y>2&&y<=5)	c[i]=7;
		else if(x>5&&y>5)	c[i]=8;
	}
}
bool dfs(int x)
{
	int i,j,l;
	remain--;
	for(i=0;i<9;i++)
	{
		if(check(i,x))
		{
			mark(i,x);
			s[x]=(i+1)+'0';
			if(remain==0)	return true;
			for(j=x+1;j<81;j++)	if(!constant[j])	break;
			if(dfs(j))	return true;
			else remark(i,x);
		}
	}	
	remain++;
	return false;
}
int main()
{
	LL i,j,k,l;
	placec();
	while(1)
	{
		scanf("%s",s);
		if(s[0]=='e')	break;
		reset(constant,0);
		reset(line,0);
		reset(cell,0);
		reset(colume,0);
		remain=81;
		for(i=0;i<81;i++)
		{
			if(s[i]!='.')
			{
				j=s[i]-'1';
				line[i/9]=line[i/9]|(1<<j);
				colume[i%9]=colume[i%9]|(1<<j);
				cell[c[i]]=cell[c[i]]|(1<<j);
				constant[i]=true;
				remain--;
			}
		}
		for(i=0;i<81;i++)	if(!constant[i])	break;
		dfs(i);
		cout<<s<<endl;
	}
	return 0;
}