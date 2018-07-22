#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[200010][3],b[3],ans;
inline bool bigger(LL *x,LL *y){
	LL i=0,j=0,k=0;
	while(i<3&&j<3){
		if(x[i]>y[j]){
			k++;
			i++;
			j++;
		}
		else j++;
	}
	return k>=2;
}
bool check(LL x){
	LL i;
	for(i=0;i<n;i++){
		if(i==x)continue;
		if(!bigger(a[x],a[i])) return false;
	}
	return true;
}
bool cmp(LL x,LL y){return x>y;}
int main(){
	LL i,j;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<3;j++)scanf("%lld",&a[i][j]);
		sort(a[i],a[i]+3,cmp);
	}
	for(i=0,ans=0;i<n;i++){
		if(!check(i))continue;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}