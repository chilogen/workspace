#include <bits/stdc++.h>
using namespace std;
int a[1010]={0},n,m;
int main(){
	int i,j,ans=10000;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>j;
		a[j]++;
	}
	for(i=1;i<=n;i++)ans=min(ans,a[i]);
	cout<<ans<<endl;
	return 0;
}