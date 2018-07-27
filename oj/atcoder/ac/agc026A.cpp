#include <bits/stdc++.h>
using namespace std;
int n,a[200];
int main(){
	int i,j;
	cin>>n;
	for(i=1,a[0]=-1;i<=n;i++)cin>>a[i];
	for(i=1,j=0;i<=n;i++){
		if(a[i]==a[i-1]){
			a[i]=-1;
			j++;
		}
	}
	cout<<j<<endl;
	return 0;
}