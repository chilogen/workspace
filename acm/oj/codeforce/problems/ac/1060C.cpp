#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,x,a[2001],b[2001],la[2001],lb[2001],sa[2001],sb[2001];
int main(){
	memset(la,127,sizeof(la));
	memset(lb,127,sizeof(lb));
	LL i,j,k;

	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		sa[i]=sa[i-1]+a[i];
	}
	for(j=1;j<=m;j++){
		cin>>b[j];
		sb[j]=sb[j-1]+b[j];
	}
	cin>>x;
	
	for(i=1;i<=n;i++)for(j=i;j<=n;j++)
		la[j-i+1]=min(la[j-i+1],sa[j]-sa[i-1]);
	for(i=1;i<=m;i++)for(j=i;j<=m;j++)
		lb[j-i+1]=min(lb[j-i+1],sb[j]-sb[i-1]);

	for(i=1,k=0;i<=n;i++)for(j=1;j<=m;j++)
		if(la[i]*lb[j]<=x)k=max(k,i*j);

	cout<<k<<endl;
	return 0;
}