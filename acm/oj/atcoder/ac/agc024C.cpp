#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[200010],t;
int main(){
	LL i,k;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0,t=0;i<n;i++){
		if(a[i]>t){
			cout<<-1<<endl;
			return 0;
		}
		t=a[i]+1;
	}
	a[n]=-1;
	for(i=n-1,k=0;i>=0;i--){
		if(a[i]==a[i+1]-1)continue;
		else k+=a[i];
	}
	cout<<k<<endl;
	return 0;
}