#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ppow(LL x){
	LL k=2,j=1;
	while(x){
		if(x&1)j*=k;
		x>>=1;
		k*=k;
	}
	return j-2;
}
int main(){
	LL n,i,j,k=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j;
		k^=j;
	}
	if(k!=0)cout<<"0\n";
	else cout<<ppow(n)<<endl;
	return 0;
}