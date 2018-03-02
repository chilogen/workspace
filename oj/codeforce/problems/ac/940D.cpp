#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL a[100010],n,i,j,k,l,r;
	char c[100010];
	cin>>n;
	for(i=0;i<n;i++)scanf("%lld",&a[i]);
	scanf("%s",c);
	l=(LL)-1e10;r=(LL)1e10;
	for(i=4;i<n;i++){
		if(c[i]=='0'){
			if(c[i-1]=='0')continue;
			k=(LL)1e10;
			for(j=0;j<5;j++){
				if(a[i-j]<k)k=a[i-j];
			}
			r=min(r,k-1);
		}
		if(c[i]=='1'){
			if(c[i-1]=='1')continue;
			k=(LL)-1e10;
			for(j=0;j<5;j++){
				if(a[i-j]>k)k=a[i-j];
			}
			l=max(l,k+1);
		}
	}
	l=max((LL)-1e9,l);
	r=min((LL)1e9,r);
	cout<<l<<" "<<r<<endl;
	return 0;
}


