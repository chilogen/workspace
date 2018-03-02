#include <bits/stdc++.h>
using namespace std;
int n,a,b,x[110],y[110],ans=0;
int main()
{
	int i,j,k;
	cin>>n>>a>>b;
	for(i=0;i<n;i++)
		cin>>x[i]>>y[i];
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			if((x[i]+x[j]<=a&&max(y[i],y[j])<=b)||(x[i]+x[j]<=b&&max(y[i],y[j])<=a))
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
			if((max(x[i],x[j])<=a&&y[i]+y[j]<=b)||(max(x[i],x[j])<=b&&y[i]+y[j]<=a))
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
			swap(x[i],y[i]);
			if((x[i]+x[j]<=a&&max(y[i],y[j])<=b)||(x[i]+x[j]<=b&&max(y[i],y[j])<=a))
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
			if((max(x[i],x[j])<=a&&y[i]+y[j]<=b)||(max(x[i],x[j])<=b&&y[i]+y[j]<=a))
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
		}
	cout<<ans<<endl;
	return 0;
}