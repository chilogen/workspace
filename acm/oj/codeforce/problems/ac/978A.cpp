#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100],n;
int main(){
	LL i,j,k;
	cin>>n;
	k=n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=n-1;i>=0;i--){
		if(a[i]==-1)continue;
		for(j=i-1;j>=0;j--){
			if(a[j]==-1)continue;
			if(a[i]==a[j]){
				a[j]=-1;
				k--;
			}
		}
	}
	cout<<k<<endl;
	for(i=0;i<n;i++)
		if(a[i]!=-1)cout<<a[i]<<" ";
	return 0;
}