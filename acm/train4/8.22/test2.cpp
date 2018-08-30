#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e18;
LL a[70][70]={0};

void add(LL x){
	LL cnt,bits;
	cnt=bits=0;
	while(x){
		if(x&1)cnt++;
		bits++;
		x>>=1;
	}
	a[bits][cnt]++;
}

int main(){
	LL i,j;
	for(i=1;i*i<=maxn;i++){
		add(i*i);
	}
	cout<<"table[]={";
	for(i=0;i<70;i++)for(j=0;j<70;j++)cout<<a[i][j]<<",";
	cout<<"};";
	return 0;
}