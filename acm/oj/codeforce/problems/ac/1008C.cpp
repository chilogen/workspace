#include <bits/stdc++.h>
using namespace std;
int n,a[100010];
int main(){
	ios::sync_with_stdio(false);
	int i,j,ans;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	i=0;j=1,ans=0;
	while(j!=n){
		if(a[i]<a[j]){
			ans++;
			i++;
		}
		j++;
	}
	cout<<ans<<endl;
	return 0;
}