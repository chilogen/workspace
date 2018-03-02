#include <bits/stdc++.h>
using namespace std;
inline bool cantake(int x1,int x2)
{
	if(x1<=x2)	return 1;
	return 0;
}
inline bool like(int x1,int x2)
{
	if(2*x1>=x2)	return 1;
	return 0;
}
int main()
{
	int v1,v2,v3,v4;
	int i,j,k;
	cin>>v1>>v2>>v3>>v4;
	for(i=0;i<=200;i++)
	{
		if(!cantake(v1,i))	continue;
		if(!cantake(v4,i))	continue;
		if(!like(v1,i))	continue;
		for(j=0;j<i;j++)
		{
			if(!cantake(v2,j))	continue;
			if(!cantake(v4,i))	continue;
			if(!like(v2,j))	continue;
			if(like(v4,j))	continue;
			for(k=0;k<j;k++)
			{
				if(!cantake(v3,k))	continue;
				if(!cantake(v4,k))	continue;
				if(!like(v3,k))	continue;
				if(!like(v4,k))	continue;
				cout<<i<<endl<<j<<endl<<k<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}