#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL d[30],c[2];

int main(){
	LL i,j,k=0,n;
	cin>>n>>c[0]>>c[1];
	for(i=0;i<n;i++)cin>>d[i];
	for(i=0,j=n-1;i<=j;i++,j--){
		if(d[i]==d[j]){
			if(d[i]!=2)continue;
			k+=min(c[0],c[1]);
			if(i!=j)k+=min(c[0],c[1]);
			continue;
		}
		if(d[i]!=2&&d[j]!=2){
			cout<<-1<<endl;
			return 0;
		}
		k+=c[d[i]+d[j]-2];
	}
	cout<<k<<endl;
	return 0;
}