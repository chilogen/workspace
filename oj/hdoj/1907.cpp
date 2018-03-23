#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n,a[50],flag;
	int i,j;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<n;i++)cin>>a[i];
		flag=j=0;
		for(i=0;i<n;i++){
			flag^=a[i];
			j+=a[i];
		}
		if(!flag){
			if(j==n)cout<<"John"<<endl;
			else cout<<"Brother"<<endl;
		}
		else{
			if(j>n)cout<<"John"<<endl;
			else cout<<"Brother"<<endl;
		}
	}
	return 0;
}