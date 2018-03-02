#include <bits/stdc++.h>
using namespace std;
int n,a;
int main(){
	int i,j,k,ans=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		j=a-1;
		k=1000000-a;
		ans=max(ans,min(j,k));
	}
	cout<<ans<<endl;
	return 0;
}