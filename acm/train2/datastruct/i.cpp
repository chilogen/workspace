#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e6+10;
LL fat[maxn],cnt[maxn];
LL getfat(LL x){
	if(x==fat[x])return x;
	else return fat[x]=getfat(fat[x]);
}
LL n,m,x,y,q,z;
int main(){
	LL i,j,k;
	for(i=0;i<maxn;i++){
		fat[i]=i;
		cnt[i]=1;
	}
	cin>>n>>m;
	while(m--){
		cin>>x>>y;
		j=getfat(x);
		k=getfat(y);
		if(j==k)continue;
		cnt[j]+=cnt[k];
		fat[k]=j;
	}
	cin>>q;
	while(q--){
		cin>>z;
		cout<<cnt[getfat(z)]<<endl;
	}
	return 0;
}