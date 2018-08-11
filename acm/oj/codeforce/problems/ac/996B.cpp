#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[100010];
int main(){
	LL i,j,k=1e18;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		k=min(k,a[i]);
	}
	j=k/n*n;
	for(i=0;i<n;i++)a[i]-=j;
	i=j=0;
	while(a[i]-j>0){
		i++;j++;
		i%=n;
	}
	cout<<i+1<<endl;
	return 0;
}