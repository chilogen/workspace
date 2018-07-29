#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e6+10;
LL fat[maxn],w[maxn],n,m;
struct cmp{
	bool operator()(LL a,LL b){
		if(w[a]==w[b])return a>b;
		else return w[a]>w[b];
	}
};
LL getfat(LL x){
	if(x==fat[x])return x;
	else return fat[x]=getfat(fat[x]);
}
int main(){
	LL i,j,t,x,y,ti,k,l;
	LL a,b;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		priority_queue<LL,vector<LL>,cmp>q;
		for(i=0;i<n;i++){
			scanf("%lld",&w[i]);
			fat[i]=i;
			q.push(i);
		}
		for(i=0,j=0;i<m;i++){
			scanf("%lld%lld",&x,&y);
			y--;
			ti=x-j;j=x;
			while(ti--){
				a=q.top();q.pop();
				b=q.top();q.pop();
				k=min(a,b);l=max(a,b);
				fat[l]=k;
				w[k]+=w[l];
				q.push(k);
			}
			printf("%lld\n",getfat(y)+1);
		}
	}
	return 0;
}