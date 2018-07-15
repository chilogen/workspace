#include <bits/stdc++.h>
using namespace std;
int n,m,a[1010],b[1010],ans=0;
int main(){
	int i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<m;i++)cin>>b[i];
	i=j=0;
	while(i<n&&j<m){
		if(b[j]>=a[i]){
			j++;
			ans++;
		}
		i++;
	}
	cout<<ans<<endl;
	return 0;
}