#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL fun[2000010];
struct wave 
{
	LL m,f,c;
}w[300010];
LL fir[2000010],nex[300010];
int main()
{
	memset(fun,0,sizeof(fun));
	memset(fir,-1,sizeof(fir));
	memset(nex,-1,sizeof(nex));
	LL n,i,j,k,l,ma=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>w[i].m>>w[i].f>>w[i].c;
		if(fir[w[i].m+w[i].c]!=-1)
			nex[i]=fir[w[i].m+w[i].c];
		fir[w[i].m+w[i].c]=i;
		ma=max(ma,w[i].m+w[i].c);
	}
	for(i=1;i<=ma;i++)
	{
		if(fir[i]==-1)
		{
			fun[i]=fun[i-1];
			continue;
		}
		else
		{
			fun[i]=max(fun[i-1],fun[i-w[fir[i]].c]+w[fir[i]].f);
			k=nex[fir[i]];
			while(k!=-1)
			{
				fun[i]=max(fun[i],fun[i-w[k].c]+w[k].f);
				k=nex[k];
			}
		}
	}
	cout<<fun[ma]<<endl;
	return 0;
}