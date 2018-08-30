#include <bits/stdc++.h>
using namespace std;
typedef long double ldd;
typedef long long LL;
typedef pair<ldd,ldd> pdd;
const LL maxn=5e4+10;
ldd inf=1e20,eps=1e-9,len;
pdd point[maxn],s,t,p,v,ans;

LL T,n,q;

inline ldd dist(pdd p1,pdd p2){return hypot(p1.first-p2.first,p1.second-p2.second);}

inline void print(ldd x,pdd p1){
	cout<<setprecision(7)<<fixed;
	cout<<x<<" "<<p1.first<<" "<<p1.second<<endl;
}

ldd cross(pdd a,pdd b){return a.first*b.second-a.second*b.first;}

inline bool equ(ldd a,ldd b){return fabs(a-b)<eps;}

bool online(pdd a,LL i,LL j){
	pdd v1=make_pair(a.first-point[i].first,a.second-point[i].second);
	pdd v2=make_pair(point[j].first-point[i].first,point[j].second-point[i].second);
	if(equ(v1.first,0))return equ(v2.first,0);
	if(equ(v1.second,0))return equ(v2.second,0);
	if(equ(v2.first,0))return equ(v1.first,0);
	if(equ(v2.second,0))return equ(v1.second,0);
	double k1,k2;
	k1=v1.first/v2.first;
	k2=v1.second/v2.second;
	return equ(fabs(k1),fabs(k2));
}

pdd inter(pdd p,pdd v){
	ldd x,y,tt;
	pdd q=ans,w=make_pair(t.first-ans.first,t.second-ans.second);
	pdd u=make_pair(p.first-q.first,p.second-q.second);
	tt=cross(w,u)/cross(v,w);
	x=p.first+tt*v.first;
	y=p.second+tt*v.second;
	return make_pair(x,y);
}

pdd inter1(pdd p,pdd v,pdd q){
	ldd x,y,tt;
	pdd w=make_pair(t.first-q.first,t.second-q.second);
	pdd u=make_pair(p.first-q.first,p.second-q.second);
	tt=cross(w,u)/cross(v,w);
	x=p.first+tt*v.first;
	y=p.second+tt*v.second;
	return make_pair(x,y);
}


bool between(pdd a,LL i,LL j){
	ldd x1,x2,y1,y2;
	x1=min(point[i].first,point[j].first);
	x2=max(point[i].first,point[j].first);
	y1=min(point[i].second,point[j].second);
	y2=max(point[i].second,point[j].second);
	if(a.first>=x1&&a.first<=x2&&a.second>=y1&&a.second<=y2)return true;
	return false;
}

pdd rotate(pdd v,ldd deg){
	ldd x,y;
	x=v.first*cos(deg)-v.second*sin(deg);
	y=v.first*sin(deg)+v.second*cos(deg);
	return make_pair(x,y);
}

ldd dot(pdd a,pdd b){return a.first*b.first+a.second*b.second;}

pdd fun(LL i,LL j){
	pdd tp1,tp2,tp3,tp4;
	ldd k,b,deg;
	k=(point[i].second-point[j].second)/(point[i].first-point[j].first);
	b=point[i].second-k*point[i].first;
	tp1.second=s.second;tp1.first=(tp1.second-b)/k;
	tp2.first=s.first-tp1.first;tp2.second=s.second-tp1.second;
	tp3.first=point[j].first-point[i].first;tp3.second=point[j].second-point[i].second;
	deg=acos(dot(tp2,tp3)/dist(tp1,s)/dist(tp1,point[j]));
	tp4=rotate(tp2,deg);
	tp3.first=tp1.first+tp4.first;
	tp3.second=tp1.second+tp4.second;
	return tp3;
}

void solve(){
	LL i,j;
	ldd l;
	pdd tp,tp1,tp2;
	for(i=0,j=1;i<n;i++,j++){
		if(online(s,i,j)){
			len=dist(s,t);
			print(len,s);
			return;
		}
		if(online(t,i,j)){
			len=dist(s,t);
			print(len,t);
			return;
		}
		tp.first=point[j].first-point[i].first;
		tp.second=point[j].second-point[i].second;
		if(tp.first==0){
			tp1.first=2*point[i].first-s.first;
			tp1.second=s.second;
		}
		else if(tp.second==0){
			tp1.first=s.first;
			tp1.second=2*point[i].second-s.second;
		}
		else tp1=fun(i,j);
		l=dist(tp1,t);
		if(l<len){
			tp2=inter1(point[i],tp,tp1);
			if(!between(tp2,i,j))continue;
			len=l;
			ans=tp1;
			p=point[i];
			v=tp;
		}
	}
	tp1=inter(p,v);
	print(len,tp1);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("flags.in","r",stdin);
	LL i,Kase=1;
	ldd x1,x2,y1,y2;
	cin>>T;
	while(T--){
		cin>>n;
		cout<<"Case "<<Kase++<<":\n";
		for(i=0;i<n;i++)	cin>>point[i].first>>point[i].second;
		point[n]=point[0];
		cin>>q;
		for(i=0;i<q;i++){
			cin>>x1>>y1>>x2>>y2;
			s=make_pair(x1,y1);
			t=make_pair(x2,y2);
			len=inf;
			solve();
		}
	}
	return 0;
}