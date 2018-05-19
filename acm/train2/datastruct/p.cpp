#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=5e4+10;
struct query{
	LL l,r,ans,ind;
};
query make_query(LL a,LL b,LL c){
	query tq;
	tq.l=min(a,b);tq.r=max(a,b);
	tq.ind=c;tq.ans=0;
	return tq;
}
LL n,q,a[maxn],b[maxn],mag;
vector<query>v;
bool cmp1(query x,query y){
	return (b[x.l]==b[y.l]?x.r<y.r:x.l<y.l);
}
bool cmp2(query x,query y){
	return x.ind<y.ind;
}
LL cnt[2][maxn]={0};
inline void updateans(LL k,LL v,LL f,LL &ans){
	ans-=(cnt[0][v]*cnt[1][v]);
	cnt[k][v]+=f;
	ans+=(cnt[0][v]*cnt[1][v]);
}
void solve(){
	LL i,k,l=0,r=-1,tans=0;
	cnt[0][a[l]]=1;
	sort(v.begin(),v.end(),cmp1);
	k=v.size();
	for(i=0;i<k;i++){
		query tq=v[i];
		while(l<tq.l){l++;updateans(0,a[l],1,tans);}
		while(l>tq.l){updateans(0,a[l],-1,tans);l--;}
		while(r<tq.r){r++;updateans(1,a[r],1,tans);}
		while(r>tq.r){updateans(1,a[r],-1,tans);r--;}
		v[i].ans=tans;
	}
	sort(v.begin(),v.end(),cmp2);
}
int main(){
	LL i,j,l1,r1,l2,r2;
	ios::sync_with_stdio(false);
	cin>>n;mag=sqrt(n);
	for(i=0;i<n;i++){
		cin>>a[i];
		b[i]=i/mag;
	}
	cin>>q;
	for(i=0,j=0;i<q;i++){
		cin>>l1>>r1>>l2>>r2;
		l1--;r1--;l2--;r2--;
		v.push_back(make_query(r1,r2,j++));
		v.push_back(make_query(r1,l2-1,j++));
		v.push_back(make_query(l1-1,r2,j++));
		v.push_back(make_query(l1-1,l2-1,j++));
	}
	solve();
	for(i=0;i<4*q;i+=4)	cout<<v[i].ans-v[i+1].ans-v[i+2].ans+v[i+3].ans<<endl;
	return 0;
}