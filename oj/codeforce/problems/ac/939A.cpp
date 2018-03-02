#include <bits/stdc++.h>
using namespace std;
int a[5010],n;
int main(){
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++){
		j=a[i];
		k=a[j];
		if(a[k]==i){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}