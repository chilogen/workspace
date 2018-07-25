#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,s,arc,a[300010],ans=0,sum[300010];
int main(){
	LL i,j,k,d1,d2;
	cin>>n;
	sum[0]=0;
	for(i=1;i<=n;i++){cin>>a[i];s+=a[i];}
	if(s%3!=0){
		cout<<0<<endl;
		return 0;
	}
	for(i=n+1,j=1;j<=n;j++,i++)a[i]=a[j];
	for(i=1;i<=2*n;i++)sum[i]=sum[i-1]+a[i];
	i=1;j=2;k=3;arc=s/3;
	while(i<=n){
		if(j<=i)j=i+1;
		d1=sum[j]-sum[i-1];
		while(d1!=arc&&i<=n){
			if(d1<arc)j++;
			if(d1>arc)i++;
			if(j<=i)j=i+1;
			d1=sum[j]-sum[i-1];
		}
		if(k<=j)k=j+1;
		d2=sum[k]-sum[j];
		while(d2!=arc&&k<=2*n){
			if(d2<arc)k++;
			if(d2>arc)break;
			d2=sum[k]-sum[j];
		}
		if(d1==d2&&d1==arc)ans++;
		i++;
	}
	cout<<ans/3<<endl;
	return 0;
}