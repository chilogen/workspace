#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e5+10,numbound=1e6+10;
LL block[maxn],a[maxn],cnt[numbound]={0};
LL ans[maxn],poww[numbound];
struct query{
	LL ind,l,r;
}q[maxn];
bool cmp(query a,query b){
	if(block[a.l]==block[b.l])return a.r<b.r;
	return block[a.l]<block[b.l];
}
LL n,t;
int main(){
	scanf("%I64d%I64d",&n,&t);
	LL i,j,tl,tr,tans=0;
	for(i=1;i<=n;i++)scanf("%I64d",&a[i]);
	a[0]=0;
	for(i=0;i<t;i++){
		scanf("%I64d%I64d",&q[i].l,&q[i].r);
		q[i].ind=i;
	}
	for(i=0;i<numbound;i++)poww[i]=i*i;
	j=520;
	for(i=0;i<maxn;i++)block[i]=i/j;
	sort(q,q+t,cmp);
	
	tl=tr=0;tans=0;
	for(i=0;i<t;i++){
		while(tl<q[i].l){
			tans-=(a[tl]*poww[cnt[a[tl]]]);
			cnt[a[tl]]--;
			tans+=(a[tl]*poww[cnt[a[tl]]]);
			tl++;
		}
		while(tl>q[i].l){
			tl--;
			tans-=(a[tl]*poww[cnt[a[tl]]]);
			cnt[a[tl]]++;
			tans+=(a[tl]*poww[cnt[a[tl]]]);
		}
		while(tr<q[i].r){
			tr++;
			tans-=(a[tr]*poww[cnt[a[tr]]]);
			cnt[a[tr]]++;
			tans+=(a[tr]*poww[cnt[a[tr]]]);
		}
		while(tr>q[i].r){
			tans-=(a[tr]*poww[cnt[a[tr]]]);
			cnt[a[tr]]--;
			tans+=(a[tr]*poww[cnt[a[tr]]]);
			tr--;
		}
		ans[q[i].ind]=tans;
	}

	for(i=0;i<t;i++)printf("%I64d\n",ans[i]);
	return 0;
}