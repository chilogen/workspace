#include <bits/stdc++.h>
using namespace std;
typedef long long LL;;
const LL maxn=1e5+10;
LL a[maxn],b[maxn],c[maxn],d[maxn],mag,n;
void update(LL l,LL r,LL v){
	LL l1=b[l]*mag,r1=min(n,l1+mag),l2=b[r]*mag,r2=min(n,l2+mag);
	LL i;
	if(b[l]==b[r]){
		for(i=l;i<=r;i++)a[i]+=v;
		for(i=l1;i<r1;i++)c[i]=a[i];
		sort(c+l1,c+r1);
		return ;
	}
	for(i=l;i<r1;i++)a[i]+=v;
	for(i=l2;i<=r;i++)a[i]+=v;
	for(i=l1;i<r1;i++)c[i]=a[i];
	for(i=l2;i<r2;i++)c[i]=a[i];
	sort(c+l1,c+r1);
	sort(c+l2,c+r2);
	for(i=b[l]+1;i<b[r];i++)d[i]+=v;
}
LL query(LL l,LL r,LL v){
	LL l1=b[l]*mag,r1=min(n,l1+mag),l2=b[r]*mag;
	LL ans=-1,tv,mid,i,j;
	if(b[l]==b[r]){
		for(i=l,tv=d[b[l]];i<=r;i++)if(a[i]+tv<v)ans=max(ans,a[i]+tv);
		return ans;
	}
	for(i=l,tv=d[b[l]];i<r1;i++)if(a[i]+tv<v)ans=max(ans,a[i]+tv);
	for(i=l2,tv=d[b[r]];i<=r;i++)if(a[i]+tv<v)ans=max(ans,a[i]+tv);
	for(i=b[l]+1,j=b[r],v--;i<j;i++){
		l=i*mag;r=min(n,l+mag);tv=d[i];
		while(r>l){
			mid=(l+r)>>1;
			if(c[mid]+tv<=v){
				if(l==mid&&c[r]+tv<=v){
					ans=max(ans,c[r]+tv);
					break;
				}
				if(l==mid){
					ans=max(ans,c[mid]+tv);
					break;
				}
				l=mid;
			}
			else r=mid;
		}
		if(c[mid]+tv<=v)ans=max(ans,c[mid]+tv);
	}
	return ans;
}
int main(){
	LL i,j,l,r,v;
	cin>>n;mag=sqrt(n);
	for(i=0;i<n;i++){
		cin>>a[i];
		b[i]=i/mag;
		c[i]=a[i];
		d[i]=0;
	}
	for(i=0;i<n;i+=mag){
		j=min(n,i+mag);
		sort(c+i,c+j);
	}
	for(i=0;i<n;i++){
		cin>>j>>l>>r>>v;
		switch(j){
			case 0:{
				update(l-1,r-1,v);
				break;
			}
			case 1:{
				cout<<query(l-1,r-1,v)<<endl;
				break;
			}
		}
	}
	return 0;
}