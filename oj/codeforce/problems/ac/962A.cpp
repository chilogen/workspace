#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,sum=0,a[200010],half;
int main(){
	LL i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	half=0;i=0;
	while(half*2<sum){
		half+=a[i];
		i++;
	}
	cout<<i<<endl;
	return 0;
}