#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
LL ans,n;
LL mpow(LL x,LL y){
	LL k=x,a=1;
	while(y){
		if(y&1){
			a*=k;
		}
		y>>=1;
		k*=k;
	}
	return a;
}
int main(){
	LL i,j;
	while(scanf("%lld",&n)!=EOF){
		ans=0;
		for(i=1;i<=15;i++){
			j=mpow(i,i);
			if(j>n)break;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}