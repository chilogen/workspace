#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e5+10;
LL t[maxn],ans[maxn/2],fat[maxn/2],cnt[maxn/2],n,k;
struct flower{LL x,y,z,ind,cnt;}f[maxn/2];
bool cmpx(flower a,flower b){
	if(a.x==b.x){
		if(a.y==b.y)return a.z<b.z;
		return a.y<b.y;
	}
	return a.x<b.x;
}
bool cmpy(flower a,flower b){return a.y<b.y;}
inline LL lowbit(LL x){return x&(-x);}

inline void add(LL x,LL v){
	for(LL i=x;i<maxn;i+=lowbit(i))t[i]+=v;
}
LL query(LL x){
	LL ans=0;
	for(LL i=x;i>0;i-=lowbit(i))ans+=t[i];
	return ans;
}

void cdq(LL l,LL r){
	if(l==r){
		ans[f[l].ind]+=(f[l].cnt-1);
		return ;
	}
	LL mid=(l+r)>>1,p1=l,p2=mid+1;
	sort(f+l,f+r+1,cmpx);
	cdq(l,mid);
	cdq(mid+1,r);
	sort(f+l,f+mid+1,cmpy);
	sort(f+mid+1,f+r+1,cmpy);
	while(p2<=r){
		while(p1<=mid&&f[p1].y<=f[p2].y){
			add(f[p1].z,f[p1].cnt);
			p1++;
		}
		ans[f[p2].ind]+=query(f[p2].z);
		p2++;
	}
	while(p1-1>=l){
		p1--;
		add(f[p1].z,-f[p1].cnt);
	}
}

void solve(){
	cin>>n>>k;
	LL i,l;
	for(i=0;i<n;i++){
		cin>>f[i].x>>f[i].y>>f[i].z;
		f[i].ind=i;
		f[i].cnt=1;
	}
	sort(f,f+n,cmpx);
	fat[f[0].ind]=f[0].ind;
	for(i=1,l=0;i<n;i++){
		if(f[i].x==f[l].x&&f[i].y==f[l].y&&f[i].z==f[l].z){
			f[l].cnt++;
			fat[f[i].ind]=f[l].ind;
		}
		else{;
			l++;
			f[l]=f[i];
			fat[f[i].ind]=f[l].ind;
		}
	}
	cdq(0,l);
	for(i=0;i<n;i++)cnt[ans[ fat[i] ]]++;
	for(i=0;i<n;i++)cout<<cnt[i]<<endl;
	//for(i=0;i<n;i++)cout<<ans[fat[i]]<<endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
	return 0;
}