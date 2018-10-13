#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,r,a[1010];
LL solve(){
	LL i,j,k,b[10010],ans=0;
	memset(b,-1,sizeof(b));
	for(i=0;i<n;i++){
		if(b[i]!=-1)continue;
		for(j=min(n-1,i+r-1);j>=max(0ll,i-r+1);j--)if(a[j]==1){
			for(k=max(0ll,j-r+1);k<=j;k++)b[k]=1;
			for(k=j;k<=min(n-1,j+r-1);k++)b[k]=1;
			ans++;
			break;
		}
		if(b[i]==-1)return -1;
	}
	return ans;
}
int main(){
	LL i;
	cin>>n>>r;
	for(i=0;i<n;i++)cin>>a[i];
	cout<<solve()<<endl;
	return 0;
}