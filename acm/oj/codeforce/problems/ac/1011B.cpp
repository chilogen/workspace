#include <bits/stdc++.h>
using namespace std;
int n,m,cnt[110]={0};
int solve(int x){
	int i,k=0;
	for(i=0;i<110;i++)k+=(cnt[i]/x);
	return k;
}
int main(){
	int i,j,k,l,r;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>j;
		cnt[j]++;
	}
	l=1;r=110;
	while(l!=r){
		k=(l+r+1)>>1;
		j=solve(k);
		if(j<n)r=k-1;
		else l=k;
	}
	j=solve(l);
	if(j>=n)cout<<l<<endl;
	else cout<<0<<endl;
	return 0;
}