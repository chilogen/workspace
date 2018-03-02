#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,ans,i,j,k;
	int a[11],b[11];
	while(1)
	{
		cin>>m>>n;;
		if(m==n&&m==0)	break;
		ans=0;
		for(i=0;i<m;i++)	cin>>a[i];
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)	cin>>b[j];
			for(j=0;j<m;j++)
			{
				if(b[j]>a[j])	break;
			}
			if(j==m)	ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}