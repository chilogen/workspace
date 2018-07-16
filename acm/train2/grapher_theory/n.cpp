#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=5e5+10;
LL n,m,vis[maxn]={0};
queue<LL>q,cost;
int main(){
	LL i,j;
	cin>>n>>m;
	if(n==m){
		cout<<0<<endl;
		return 0;
	}
	q.push(n);cost.push(0);vis[n]=1;
	while(!q.empty()){
		i=q.front();q.pop();
		j=cost.front();cost.pop();
		if(2*i==m){
			cout<<j+2<<endl;
			return 0;
		}
		if(i-3==m){
			cout<<j+3<<endl;
			return 0;
		}
		if(2*i<=500000&&!vis[2*i]){
			vis[2*i]=1;
			q.push(2*i);
			cost.push(j+2);
		}
		if(i-3>=1&&!vis[i-3]){
			vis[i-3]=1;
			q.push(i-3);
			cost.push(j+3);
		}
	}
	cout<<-1<<endl;
	return 0;
}