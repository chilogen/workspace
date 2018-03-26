#include <bits/stdc++.h>
using namespace std;
int a[100010],n;
int main(){
	int i,j=0,k=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		k+=abs(a[i]-j);
		j=a[i];
	}
	a[0]=a[i]=0;k+=abs(j);
	for(i=1;i<=n;i++){
		if(a[i-1]<=a[i+1]){
			if(a[i]>=a[i-1]&&a[i]<=a[i+1])cout<<k<<endl;
			else if(a[i]<a[i-1]) cout<<k-2*abs(a[i]-a[i-1])<<endl;
			else cout<<k-2*abs(a[i]-a[i+1])<<endl;
		}
		else{
			if(a[i]>=a[i+1]&&a[i]<=a[i-1])cout<<k<<endl;
			else if(a[i]<a[i+1])cout<<k-2*abs(a[i]-a[i+1])<<endl;
			else cout<<k-2*abs(a[i]-a[i-1])<<endl;
		}
	}
	return 0;
}