#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL sum[900000]={0},px[900000],py[900000];
LL h,w,d,q,l,r;
int main(){
	LL i,j,k;
	cin>>h>>w>>d;
	for(i=1;i<=h;i++)for(j=1;j<=w;j++){
		cin>>k;
		px[k]=i;	py[k]=j;
	}
	j=h*w;
	for(i=d+1;i<=j;i++){
		k=i-d;
		sum[i]=sum[k]+abs(px[i]-px[k])+abs(py[i]-py[k]);
	}
	cin>>q;
	while(q--){
		cin>>l>>r;
		cout<<sum[r]-sum[l]<<endl;
	}
	return 0;
}