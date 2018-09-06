#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL lm,rm,n,k;

bool query(LL l,LL r){
	cout<<l<<" "<<r<<endl;
	cout.flush();
	string ans;
	cin>>ans;
	return ans=="Yes";
}
/*
LL now=-9;
bool query(LL l,LL r){
	now+=10;
	cout<<l<<" "<<" "<<r<<" "<<now<<endl;
	if(now>=l&&now<=r)return true;
	return false;
}*/

void shinklr(){
	LL l=lm,r=rm,mid;
	while(l<r-4*k&&l<r){
		mid=(l+r)>>1;
		if(l==mid)break;
		if(query(l,mid)){
			l=max(1ll,l-k);
			r=min(n,mid+k);
		}
		else{
			if(l==mid)break;
			l=max(1ll,mid-k+1);
			r=min(n,r+k);
		}
	}
	lm=l;rm=r;
}

void solve(){
	cin>>n>>k;
	lm=1;rm=n;
	LL j;
	while(1){
		shinklr();
		j=lm+rand()%(rm-lm+1);
		if(query(j,j))break;
		lm=max(1ll,lm-k);
		rm=min(n,rm+k);
	}
}


int main(){
	srand((unsigned)time(NULL));
	solve();
	return 0;
}