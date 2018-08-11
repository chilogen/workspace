#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,q;
LL T[1100]={0};
LL lowbit(LL x){return x&(-x);}
void insert(LL x){
	LL i;
	for(i=x;i<1100;i+=lowbit(i))T[i]++;
}
LL query(LL x){
	LL i,k=0;
	for(i=x;i>0;i-=lowbit(i))k+=T[i];
	return k;
}
string s,t;
vector<LL>p;
void ff(){
	LL i,j,k;
	for(i=0;i<n;i++){
		for(j=0,k=i;j<m;j++,k++){
			if(s[k]!=t[j])break;
		}
		if(j==m)p.push_back(i+1);
	}
}
int main(){
	LL i,l,r,j,k;
	cin>>n>>m>>q>>s>>t;
	ff();
	k=p.size();
	for(i=0;i<k;i++)insert(p[i]);
	for(i=0;i<q;i++){
		cin>>l>>r;
		if(r-l+1<m){
			cout<<0<<endl;
			continue;
		}
		j=query(l-1);
		k=query(r-m+1);
		cout<<k-j<<endl;
	}
	return 0;
}