#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL a[101],n,ans=0;
	LL i,j,k,x;
	string o;
	bool fine[101];
	for(i=0;i<=100;i++)
	{
		fine[i]=true;
		a[i]=i;
	}
	cin>>n;
	while(n--)
	{
		cin>>o;
		if(o=="ADD")
		{
			cin>>x;
			for(i=1;i<=100;i++)
			{
				if(fine[i])
				a[i]+=x;
			}
		}	
		else if(o=="SUBTRACT")
		{
			cin>>x;
			for(i=1;i<=100;i++)
			{
				if(fine[i])
				{
					a[i]-=x;
					if(a[i]<0)
					{
						fine[i]=false;
						ans++;
					}
				}
			}

		}
		else if(o=="MULTIPLY")
		{
			cin>>x;
			for(i=1;i<=100;i++)
			{
				if(fine[i])
				a[i]*=x;
			}

		}
		else if(o=="DIVIDE")
		{
			cin>>x;
			for(i=1;i<=100;i++)
			{
				if(a[i]==0)	continue;
				if(fine[i])
				{
					if(a[i]>=x&&a[i]%x==0)
					{
						a[i]=a[i]/x;
					}
					else
					{
						fine[i]=false;
						ans++;
					}
				}
			}

		}
	}
	cout<<ans<<endl;
	return 0;
}