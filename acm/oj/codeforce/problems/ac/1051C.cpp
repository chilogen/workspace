#include <bits/stdc++.h>
using namespace std;
int vis[110]={0},cnt[110]={0},a[110],ans[110],n;
vector<int>pos[2];
int main(){
	int i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(i=j=k=0;i<n;i++){
		if(vis[a[i]]!=0){
			ans[i]=vis[a[i]];
			continue;
		}
		if(cnt[a[i]]==2){
			ans[i]=-1;
			vis[a[i]]=-1;
			continue;
		}
		if(cnt[a[i]]==1){
			if(j<k){
				j++;
				vis[a[i]]=-1;
				ans[i]=-1;
				continue;
			}
			k++;
			vis[a[i]]=1;
			ans[i]=1;
		}
	}
	for(i=0;i<n;i++){
		if(cnt[a[i]]<3)continue;
		if(vis[a[i]]!=0){
			ans[i]=vis[a[i]];
			continue;
		}
		if(j==k){
			ans[i]=vis[a[i]]=-1;
			continue;
		}
		if(j<k){
			ans[i]=-1;
			vis[a[i]]=1;
			j++;
			continue;
		}
		k++;
		ans[i]=1;
		vis[a[i]]=-1;
	}
	if(j!=k){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for(i=0;i<n;i++){
		if(ans[i]==-1)cout<<'A';
		else if(ans[i]==1)cout<<'B';
		else cout<<'0';
	}
	return 0;
}