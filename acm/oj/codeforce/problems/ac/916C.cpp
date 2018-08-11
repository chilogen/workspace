#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
bool isprime(LL x){
	LL i;
	for(i=2;i<=sqrt(x);i++){
		if(x%i==0)	return false;
	}
	return true;
}
LL findprime(int x){
	while(!isprime(x)){x++;}
	return x;
}
int main(){
	cin>>n>>m;
	if(n==2){
		cout<<"7 7\n";
		cout<<"1 2 7\n";
		return 0;
	}
	LL i,j,k=0,mst;
	mst=findprime(n-1);
	k=mst-n+1;
	cout<<2<<" "<<mst<<endl;
	for(i=1;i<=n;i++){
		if(i==2)	continue;
		if(i==3&&k>0){
			cout<<3<<" "<<2<<" "<<1+k<<endl;
			continue;
		}
		cout<<i<<" "<<2<<" "<<1<<endl;
	}
	m-=(n-1);
	for(i=1;i<n&&m>0;i++){
		if(i==2)	continue;
		for(j=i+1;j<=n&&m>0;j++){
			if(j==2)	continue;
			cout<<i<<" "<<j<<" "<<100000000<<endl;
			m--;
		}
	}
}