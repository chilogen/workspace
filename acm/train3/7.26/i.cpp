#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=200010;
LL a[maxn],cnt[2]={0},n,ans=0;
LL vis[maxn]={0};
struct cmp{
	bool operator()(LL x,LL y){
		return x>y;
	}
};
priority_queue<LL,vector<LL>,cmp>q;
void count(){
	LL i,k;
	for(i=0;i<n;i++){
		k=sqrt(a[i]);
		if(k*k==a[i]){
			cnt[1]++;
			vis[i]=1;
		}
		else cnt[0]++;
	}
}
void solve(){
	LL i,j,k;
	for(i=0;i<n;i++){
		if(vis[i])continue;
		j=sqrt(a[i]);
		k=(j+1)*(j+1);j=j*j;
		q.push(min(abs(a[i]-k),abs(a[i]-j)));
	}
	while(cnt[0]>n/2){
		ans+=q.top();cnt[0]--;q.pop();
	}
}
void solve1(){
	LL i;
	for(i=0;i<n;i++){
		if(!vis[i])continue;
		if(a[i]==0)q.push(2);
		else q.push(1);
	}
	while(cnt[1]>n/2){
		ans+=q.top();cnt[1]--;q.pop();
	}
}
int main(){
	LL i,k;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	count();
	k=n/2;
	if(cnt[1]>=k)solve1();
	else solve();
	cout<<ans<<endl;
	return 0;
}