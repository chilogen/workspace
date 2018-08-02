#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100010],t,n,s;
LL check(LL x){
	queue<LL>q[2];
	LL i,j,k,l,ans=0,tmp,m;
	for(i=0;i<n;i++)q[0].push(a[i]);
	if((n-1)%(x-1)!=0){
		j=(n-1)%(x-1)+1;
		k=0;
		for(i=0;i<j;i++){
			k+=q[0].front();q[0].pop();
		}
		q[1].push(k);
		ans=k;
	}
	k=0;l=1;
	j=(n-1)/(x-1);
	for(i=0;i<j;i++){
		tmp=0;
		for(m=0;m<x;m++){
			if(q[k].empty()){
				tmp+=q[l].front();q[l].pop();
			}
			else if(q[l].empty()){
				tmp+=q[k].front();q[k].pop();
			}
			else{
				if(q[l].front()<q[k].front()){
					tmp+=q[l].front();
					q[l].pop();
				}
				else{
					tmp+=q[k].front();
					q[k].pop();
				}
			}
		}
		ans+=tmp;
		q[l].push(tmp);
		swap(l,k);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	LL i,l,r,mid;
	cin>>t;
	while(t--){
		cin>>n>>s;
		for(i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		l=2;r=n;
		while(l!=r){
			mid=(l+r)>>1;
			i=check(mid);
			if(i>s)l=mid+1;
			else r=mid;
		}
		cout<<l<<endl;
	}
	return 0;
}