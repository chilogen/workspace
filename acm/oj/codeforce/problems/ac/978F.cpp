#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e5+10;
LL quar[maxn],lessthan[maxn],a[maxn];
LL n,o;
struct programmer
{
	LL ind,r;
}p[maxn];
bool cmp(programmer a,programmer b){
	return a.r>b.r;
}
int main(){
	LL i,j,l,m,k;
	cin>>n>>o;
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		p[i].r=a[i];
		p[i].ind=i;
	}
	sort(p,p+n,cmp);
	memset(lessthan,0,sizeof(lessthan));
	memset(quar,0,sizeof(quar));
	for(i=n-1,j=0,k=0;i>=0;i--){
		if(i+1<n&&p[i].r!=p[i+1].r){
			j+=k;
			k=0;
		}
		lessthan[p[i].ind]=j;
		k++;
	}
	for(i=0;i<o;i++){
		scanf("%lld%lld",&l,&m);
		l--;m--;
		if(a[l]>a[m])quar[l]++;
		if(a[l]<a[m])quar[m]++;
	}
	for(i=0;i<n;i++){
		cout<<lessthan[i]-quar[i]<<" ";
	}
	return 0;
}