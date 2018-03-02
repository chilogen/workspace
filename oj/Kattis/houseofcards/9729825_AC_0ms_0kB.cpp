#include <bits/stdc++.h>
using namespace std;
char c;
int a[2000];
int len=2;
inline void add()
{
	int i,j,k;
	for(i=len-1;i>=0;i--)
	{
		if(a[i]==9)
		{
			a[i]=0;
			continue;
		}
		a[i]++;
		return ;
	}
}
void output()
{
	int i,j,k;
	for(i=0;i<len;i++)
		if(a[i]!=0)	break;
	for(;i<len;i++)
		cout<<a[i];
	cout<<endl;
}
int main()
{
	int i,j,k;
	int b[2][50]={{5,8,13,16,21,24,29,32,37,40,45,48,53,56,61,64,69,72,77,80,85,88,93,96},{1,4,9,12,17,20,25,28,33,36,41,44,49,52,57,60,65,68,73,76,81,84,89,92,97}};
	set<int>s1,s2;
	for(i=0;i<24;i++)	s1.insert(b[0][i]);
	for(i=0;i<25;i++)	s2.insert(b[1][i]);
	memset(a,0,sizeof(a));
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='\n')	continue;
		a[len]=c-'0';
		len++;
	}
	i=1;
	while(1)
	{
		i=a[len-3];
		k=a[len-2]*10+a[len-1];
		if(i%2==0)
		{
			if(k==0)
			{
				output();
				break;
			}
			if(s1.count(k)!=0)
			{
				output();
				break;
			}
			add();
		}
		else if(i%2==1)
		{
			if(s2.count(k)!=0)
			{
				output();
				break;
			}
			add();
		}
	}
	return 0;
}