#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[100010],ma=0,half;
int main(){
	LL i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	half=ma/2;
	for(i=0;i<n;i++)if(a[i]==ma)break;
	while(i<n-1){
		swap(a[i],a[i+1]);
		i++;
	}
	for(i=0,j=a[0],k=1e9;i<n-1;i++){
		if(k>abs(half-a[i])){
			j=a[i];
			k=abs(half-a[i]);
		}
	}
	cout<<ma<<" "<<j<<endl;
	return 0;
}