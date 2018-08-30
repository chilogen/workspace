#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10;


struct point{
	LL x,y,v;
}p[maxn];

struct xtree{
	LL l,r,v;
}T[maxn<<2];


bool cmp(point a,point b){
	if(a.y==b.y)return a.x<b.x;
	return a.y<b.y;
}

bool low(point a,point b){
	return ((a.x<b.x)&&(a.y<b.y));
}

vector<LL>x;
map<LL,LL>ma;

void build(LL x,LL l,LL r){
	T[x].l=l;T[x].r=r;
	if(l==r){
		T[x].v=0;
		return ;
	}
	LL mid=(l+r)>>1;
	build(x<<1,l,mid);
	build((x<<1)+1,mid+1,r);
	T[x].v=0;
}

void insert(LL x,LL p,LL v){
	if(T[x].l==T[x].r){
		T[x].v=max(T[x].v,v);
		return ;
	}
	LL mid=(T[x].l+T[x].r)>>1;
	if(p<=mid)insert(x<<1,p,v);
	else insert((x<<1)+1,p,v);
	T[x].v=max(T[x<<1].v,T[(x<<1)+1].v);
}

LL query(LL x,LL p){
	if(T[x].r<=p)return T[x].v;
	LL mid=(T[x].l+T[x].r)>>1;
	LL k=query(x<<1,p);
	if(p>mid)k=max(k,query((x<<1)+1,p));
	return k;
}

void solve(){
	LL i,j,k,n,ans=0;
	x.clear();ma.clear();
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y>>p[i].v;
		x.push_back(p[i].x);
	}
	sort(x.begin(),x.end());
	vector<LL>::iterator it=unique(x.begin(),x.end());
	x.resize(it-x.begin());k=x.size();
	for(i=0;i<k;i++)ma[x[i]]=i+1;
	for(i=1;i<=n;i++)p[i].x=ma[p[i].x];
	sort(p+1,p+1+n,cmp);p[0]=p[1];
	vector<pair<LL,LL> >tv;
	build(1,1,k);
	for(i=1;i<=n;i++){
		if(p[i].y!=p[i-1].y){
			k=tv.size();
			for(j=0;j<k;j++)insert(1,tv[j].first,tv[j].second);
			tv.clear();
		}
		j=query(1,p[i].x-1);
		p[i].v+=j;
		ans=max(ans,p[i].v);
		tv.push_back(make_pair(p[i].x,p[i].v));
	}
	cout<<ans<<endl;
}

int main(){
	int t;
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}