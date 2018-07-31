#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e5+10;
LL x[maxn],y[maxn],ans=8e18;;
LL n;
LL area(LL i,LL j,LL k){
	LL tx[4],ty[4];
	tx[0]=tx[3]=x[i];ty[0]=ty[3]=y[i];
	tx[1]=x[j];ty[1]=y[j];
	tx[2]=x[k];ty[2]=y[k];
	int it;
	LL s=0;
	for(it=0;it<3;it++){
		s+=(tx[it]*ty[it+1]-tx[it+1]*ty[it]);
	}
	return abs(s);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	LL i,j,k,l;
	cin>>n;
	for(i=0;i<n;i++)cin>>x[i]>>y[i];
	for(i=0;i<n;i++){
		j=(i+1)%n;
		for(l=1;l<min((LL)50,n);l++){
			k=(j+l)%n;
			if(k!=i&&k!=j)ans=min(ans,area(i,j,k));
			k=(j-l+n)%n;
			if(k!=i&&k!=j)ans=min(ans,area(i,j,k));
		}
	}
	cout<<ans<<endl;
	return 0;
}