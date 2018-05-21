#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[2000],n;
int main(){
	LL i,j,k;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(i=0,j=0,k=n-1;;i++){
		if(n==1)break;
		if(i%2==0)k--;
		else j++;
		n--;
	}
	if(i%2==0)cout<<a[j]<<endl;
	else cout<<a[k]<<endl;
	return 0;
}