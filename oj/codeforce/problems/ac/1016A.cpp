#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[200010];
int main(){
	LL i,j,k,remain;
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>a[i];
	remain=m;
	for(i=0;i<n;i++){
		j=min(remain,a[i]);
		remain-=j;
		a[i]-=j;
		if(remain!=0){
			cout<<"0 ";
			continue;
		}
		j=a[i]/m;
		k=a[i]%m;
		cout<<j+1<<" ";
		remain=m-k;
	}
	return 0;
}