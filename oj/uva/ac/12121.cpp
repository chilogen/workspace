#include <bits/stdc++.h>
using namespace std;
int n,a[10];
inline bool ok(int *b)
{
	int i;
	for(i=1;i<=n;i++)	if(b[i]!=i)	return 0;
	return 1;	
}
inline void ctrl_xv(int *a,int x,int y,int k)
{
	
}
bool opera(int *b,int cur,int Max)
{
	int tmp[10],i,j;
}
int main()
{
	int i,j,kase=0;
	while(scanf("%d",&n))
	{
		kase++;
		if(n==0)	break;
		for(i=0;i<n;i++)	scanf("%d",&a[i]);
		for(i=0;i<10;i++)	if(opera(a,0,i))	printf("Case %d: %d\n",kase,i),break;
	}
	return 0;
}