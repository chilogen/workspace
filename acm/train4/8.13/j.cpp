#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e6+10,inf=1e18;
string s;
LL n,m;
LL d[maxn],cnt[maxn];
double ans;
struct node{
	LL mind,sumd,sumf;
};
struct tree{
	node v;
	LL lef,rig;
}T[maxn<<2];
void build(LL x,LL l,LL r){
	LL i,j,k;
	T[x].lef=l;T[x].rig=r;
	if(l==r){
		T[x].v=(node){d[l],d[l],cnt[l]};
		return;
	}
	LL mid=(l+r)>>1;
	build(x<<1,l,mid);
	build((x<<1)+1,mid+1,r);
	i=min(T[x<<1].v.mind,T[(x<<1)+1].v.mind);
	j=T[x<<1].v.sumd+T[(x<<1)+1].v.sumd;
	k=T[x<<1].v.sumf+T[(x<<1)+1].v.sumf;
	T[x].v=(node){i,j,k};
}
node query(LL x,LL l,LL r){
	LL mid=(T[x].lef+T[x].rig)>>1;
	if(T[x].lef>=l&&T[x].rig<=r)return T[x].v;
	node a=(node){inf,0ll,0ll},b=(node){inf,0ll,0ll};
	if(l<=mid)a=query(x<<1,l,r);
	if(r>mid)b=query((x<<1)+1,l,r);
	LL i,j,k;
	i=min(a.mind,b.mind);
	j=a.sumd+b.sumd;
	k=a.sumf+b.sumf;
	return (node){i,j,k};
}
double check(LL l,LL r){
	double x,y;
	node a=query(1,l,r);
	x=a.sumd-m*a.mind;
	y=x+0.5*a.sumf;
	return y;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	LL i,j,k,l,r,t,kase=1;
	cin>>t;
	while(t--){
		ans=inf;
		memset(cnt,0,sizeof(cnt));
		cout<<"Case #"<<kase++<<": ";
		cin>>n>>m>>s;
		l=s.length();
		for(i=1,j=0,k=inf;i<=l;i++){
			d[i]=j;
			if(s[i-1]=='/'){
				j++;
				cnt[i]=1;
			}
			else if(s[i-1]=='\\'){
				j--;
				d[i]--;
				cnt[i]=1;
			}
			k=min(k,d[i]);
		}	
		for(i=1;i<=n;i++)d[i]-=k;
		build(1,1,n);
		l=1;r=m;
		while(r<=n){
			ans=min(ans,check(l,r));
			l++;r++;
		}
		cout<<setprecision(1)<<fixed<<ans<<endl;
	}
	return 0;
}