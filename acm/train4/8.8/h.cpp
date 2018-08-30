#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
unsigned x,y,z;
unsigned rng61() {
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}
LL n,m;
LL a[10000010],ans[100];
struct tt{
	LL ind,v;
}b[100];
bool cmp(tt x,tt y){return x.v>y.v;}
LL nth(LL kth,LL *s,LL *t){
	if(t-s<kth||kth==0)return *s;
	LL l,r,k=rand()%(t-s);
	swap(s[0],s[k]);
	k=t-s;
	for(l=r=1;r<k;r++){
		if(s[r]<s[0]){
			swap(s[l],s[r]);
			l++;
		}
	}
	swap(s[0],s[l-1]);
	if(kth==l)return s[l-1];
	if(kth<l)return nth(kth,s,s+l);
	if(kth>l)return nth(kth-l,s+l,t);
	return 0;
}

int main(){
	LL i,kase=1,k;
	while(scanf("%lld",&n)!=EOF){
		cout<<"Case #"<<kase++<<": ";
		cin>>m>>x>>y>>z;
		for(i=0;i<n;i++)a[i]=rng61();
		for(i=0;i<m;i++){
			cin>>b[i].v;
			b[i].ind=i;
		}
		sort(b,b+m,cmp);
		k=n;
		for(i=0;i<m;i++){
			/*
			ans[b[i].ind]=nth(b[i].v,a,a+k);
			k=b[i].v;
			*/
			nth_element(a,a+b[i].v,a+k);
			ans[b[i].ind]=a[b[i].v];
			k=b[i].v;
		}
		for(i=0;i<m-1;i++)cout<<ans[i]<<" ";
		cout<<ans[i]<<endl;
	}
	return 0;
}