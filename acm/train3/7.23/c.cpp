#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[3],b[2];
LL solve(LL c[]){
	LL i,ans=0;
	for(i=0;i<2;i++)ans+=c[i];
	for(i=0;i<2;i++){
		if(c[i]>b[i])ans=min(ans,b[i]);
	}
	return ans;
}
int main(){
	cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1];
	LL c[3],d[3];
	memcpy(c,a,sizeof(a));
	memcpy(d,a,sizeof(a));
	c[0]+=a[2];d[1]+=a[2];
	cout<<min(solve(c),solve(d));
	return 0;
}