#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,x,n;
int main(){
	int i,j,k;
	cin>>t;
	while(t--){
		cin>>x>>n;
		if(x<n){
			cout<<-1<<endl;
			continue;
		}
		j=x%n;k=x/n;
		if(j==0)for(i=0;i<n;i++)cout<<k<<" ";
		else{
			k++;i=0;
			while(x%(n-i)!=0){
				cout<<k-1<<" ";
				i++;
				x-=(k-1);
			}
			for(;i<n;i++)cout<<k<<" ";
		}
		cout<<endl;
	}
	return 0;
}