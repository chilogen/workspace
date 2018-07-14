#include <bits/stdc++.h>
using namespace std;
int a[100010][2],n;
int main(){
	int i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j>>k;
		a[i][0]=max(j,k);
		a[i][1]=min(j,k);
	}
	for(i=0;i<n-1;i++){
		if(a[i][0]<a[i+1][1])break;
		if(a[i][0]<a[i+1][0])swap(a[i+1][0],a[i+1][1]);
	}
	if(i!=n-1)cout<<"NO\n";
	else cout<<"YES\n";
	return 0;
}