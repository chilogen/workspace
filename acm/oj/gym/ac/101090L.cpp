#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,ans,r[1000],b[1000],i,j,k,nr,nb;
	char c;
	while(cin>>n)
	{
		ans=0;
		memset(r,0,sizeof(r));
		memset(b,0,sizeof(b));
		nr=nb=0;
		for(i=0;i<n;i++)
		{
			cin>>j;
			while(1)
			{
				cin>>c;
				if(c=='R'||c=='B')	break;
			}
			if(c=='R')
			{
				r[nr]=j;
				nr++;
			}
			else if(c=='B')
			{
				b[nb]=j;
				nb++;
			}
		}
		if(nb+nr<=1)
		{
			cout<<"0"<<endl;
			continue;
		}
		sort(b,b+nb,cmp);
		sort(r,r+nr,cmp);
		i=min(nr,nb);
		j=2*i;
		for(k=0;k<i;k++)
		{
			ans+=r[k];
			ans+=b[k];
		}
		ans-=j;
		cout<<ans<<endl;
	}
	return 0;
}