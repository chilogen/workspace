#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10,inf=1e18;
LL mag;
LL a[maxn],b[maxn],c[maxn],sum[maxn];
LL n,q,cmd,l,r,x;
void update(){
	LL i;
	LL l1=mag*b[l],r1=l1+mag,l2=mag*b[r],r2=l2+mag;
	if(b[l]==b[r]){
		for(i=l;i<=r;i++)a[i]+=x;
		for(i=l1;i<r1;i++)c[i]=a[i];
		sort(c+l1,c+min(n,r1));
		return;
	}
	for(i=l;i<r1;i++)a[i]+=x;
	for(i=l2;i<=r;i++)a[i]+=x;
	for(i=l1;i<r1;i++)c[i]=a[i];
	for(i=l2;i<r2;i++)c[i]=a[i];
	sort(c+l1,c+min(n,r1));
	sort(c+l2,c+min(n,r2));
	
	for(i=b[l]+1;i<b[r];i++)sum[i]+=x;
}
LL query(){
	LL la=1,ra=0,i,mid,found=0,tx;
	for(i=b[0];i<=b[n-1]&&!found;i++){
		l=mag*i;r=min(n,l+mag);tx=x-sum[i];
		while(r>l){
			mid=(l+r)>>1;
			if(c[mid]==tx){
				found=1;
				l=mag*i;r=l+mag;
				for(la=l;la<r;la++)if(a[la]==tx)break;
				break;
			}
			if(c[mid]<tx){
				if(l==mid&&c[mid]!=tx)break;
				else l=mid;
			}
			else r=mid;
		}
	}
	for(i=b[n-1],found=0;i>=b[0]&&!found;i--){
		l=mag*i;r=min(n,l+mag);tx=x-sum[i];
		while(r>l){
			mid=(l+r)>>1;
			if(c[mid]==tx){
				found=1;
				l=mag*i;r=l+mag;
				for(ra=r-1;ra>=l;ra--)if(a[ra]==tx)break;
				break;
			}
			if(c[mid]<tx){
				if(l==mid&&c[mid]!=tx)break;
				else l=mid;
			}
			else r=mid;
		}
	}
	return ra-la;
}
int main(){
	LL i;
	memset(sum,0,sizeof(sum));
	for(i=0;i<maxn;i++)c[i]=inf;
	scanf("%lld%lld",&n,&q);
	mag=sqrt(n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		c[i]=a[i];
		b[i]=i/mag;
	}
	for(i=0;i<n;i+=mag)sort(c+i,c+min(n,i+mag));
	while(q--){
		scanf("%lld",&cmd);
		switch(cmd){
			case 1:{
				scanf("%lld%lld%lld",&l,&r,&x);
				l--;r--;
				if(x!=0)update();
				break;
			}
			case 2:{
				scanf("%lld",&x);
				printf("%lld\n",query());
				break;
			}
		}
	}
	return 0;
}