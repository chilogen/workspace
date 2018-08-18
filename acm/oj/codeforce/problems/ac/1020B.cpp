#include <bits/stdc++.h>
using namespace std;
int cnt[1010],n,p[1010];
void solve(int x){
	memset(cnt,0,sizeof(cnt));
	while(cnt[x]==0){
		cnt[x]++;
		x=p[x];
	}
	cout<<x<<" ";
}
int main(){
	int i;
	cin>>n;
	for(i=1;i<=n;i++)cin>>p[i];
	for(i=1;i<=n;i++)solve(i);
	return 0;
}