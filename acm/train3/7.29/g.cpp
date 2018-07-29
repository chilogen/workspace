#include <iostream>
using namespace std;
double a;
int t;
int main(){
	cin>>t;
	while(t--){
		cin>>a;
		printf("%.6f\n",a);
	}
}/*
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=300;
double d[2][maxn+2];
double ans[1000010];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	LL t,n,i,k,l;
	double a;
	memset(d,0,sizeof(d));
	d[0][0]=1;
	k=0;
	for(l=0;l<=1000000;l++){
		d[!k][0]=d[k][1];
		for(i=1;i<maxn;i++){
			d[!k][i]=d[k][i-1]+d[k][i+1];
			d[!k][i]/=2;
		}
		ans[l]=0;
		for(i=1;i<maxn;i++){
			a=d[k][i]*2;
			ans[l]+=i*i*a;
		}
		k=!k;
	}
	cin>>t;
	while(t--){
		cin>>n;
		printf("%.7f\n",ans[n]);
	}
	return 0;
}*/