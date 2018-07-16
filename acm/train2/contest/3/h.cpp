#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL p,k,n,a[1010],b[1010];
int main(){
	LL i,j;
	cin>>p;
	while(p--){
		cin>>k>>n;
		for(i=0;i<n;i++){
			cin>>a[i];
			b[i]=a[i];
		}
		sort(b,b+n);
		for(i=0,j=0;i<n;i++){
			if(a[i]==b[j])j++;
		}
		cout<<k<<" "<<n-j<<endl;
	}
	return 0;
}