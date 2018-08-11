#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
void get(char a,LL &b)
{
	switch(a)
	{
		case 118:
		{
			b=270;
			return ;
		}
		case 60:
		{
			b=180;
			return ;
		}
		case 94:
		{
			b=90;
			return ;
		}
		case 62:
		{
			b=0;
		}
	}
}
int main()
{
	LL s,e,t,i,j;
	bool CCW,CW;
	char a,b;
	cin>>a>>b>>t;
	t=t%4;
	get(a,s);	get(b,e);
	CCW=CW=false;
	if((s+t*90)%360==e)
	{
		CCW=true;
	}
	if((s+720-t*90)%360==e)
	{
		CW=true;
	}
	if(CW&&CCW)
		puts("undefined");
	else if(CW)
		puts("cw");
	else puts("ccw");
	return 0;
}