#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[]={100,20,10,5,1},ans=0,n;
int main(){
	LL i,j;
	cin>>n;
	for(i=0;i<5&&n>0;i++){
		j=n/a[i];
		ans+=j;
		n-=(j*a[i]);
	}
	cout<<ans<<endl;;
	return 0;
}