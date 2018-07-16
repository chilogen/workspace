#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10,inf=1e10;;
LL a[maxn],b[maxn];
LL k[20],f[20],l[20];
LL n,c,Min,Max,ans;
double Sum,Cnt,val;
char s1[10],s2[10];
struct node{
	LL left,right,mi,ma,sum,cnt;
}T[maxn<<2];
void build(LL x,LL l,LL r){
	T[x].left=l;T[x].right=r;
	if(l==r){
		T[x].mi=inf;
		T[x].ma=-inf;
		T[x].sum=T[x].cnt=0;
		return ;
	}
	LL mid=(l+r)>>1;
	build(x<<1,l,mid);
	build((x<<1)+1,mid+1,r);
	T[x].mi=inf;
	T[x].ma=-inf;
	T[x].sum=T[x].cnt=0;
}
void update(LL x,LL k,LL v){
	if(T[x].left==T[x].right){
		T[x].sum+=v;T[x].cnt++;
		T[x].mi=min(T[x].mi,v);
		T[x].ma=max(T[x].ma,v);
		return;
	}
	LL mid=(T[x].left+T[x].right)>>1;
	if(k<=mid)update(x<<1,k,v);
	if(k>mid)update((x<<1)+1,k,v);
	T[x].mi=min(T[x<<1].mi,T[(x<<1)+1].mi);
	T[x].ma=max(T[x<<1].ma,T[(x<<1)+1].ma);
	T[x].sum=T[x<<1].sum+T[(x<<1)+1].sum;
	T[x].cnt=T[x<<1].cnt+T[(x<<1)+1].cnt;
}
void query(LL x,LL l,LL r){
	if(T[x].left>=l&&T[x].right<=r){
		Min=min(Min,T[x].mi);
		Max=max(Max,T[x].ma);
		Cnt+=T[x].cnt;
		Sum+=T[x].sum;
		return;
	}
	LL mid=(T[x].left+T[x].right)>>1;
	if(l<=mid)query(x<<1,l,r);
	if(r>mid)query((x<<1)+1,l,r);
}
int main(){
	vector<LL>v;
	vector<LL>::iterator p;
	map<LL,LL>m;
	LL i,j;
	while(cin>>n){
		v.clear();
		m.clear();
		memset(T,0,sizeof(T));
		v.push_back(0);
		for(i=0;i<n;i++){
			scanf("%lld%lld",&a[i],&b[i]);
			v.push_back(a[i]);
		}
		p=unique(v.begin(),v.end());
		v.resize(distance(v.begin(),p));j=v.size();
		for(i=0;i<j;i++)	m[v[i]]=i+1;
		build(1,1,j);
		for(i=0;i<n;i++)update(1,m[a[i]],b[i]);
		cin>>c;
		for(i=0;i<c;i++){
			scanf("%s%s%lld",s1,s2,&l[i]);
			if(strcmp(s1,"gt")==0)k[i]=0;
			else k[i]=1;
			if(strcmp(s2,"min")==0)f[i]=-1;
			else if(strcmp(s2,"avg")==0)f[i]=0;
			else f[i]=1;
		}
		for(i=0;i<c;i++){
			ans=0;
			for(j=0;j<n;j++){
				Min=inf;Max=-Min;Cnt=Sum=0;
				p=lower_bound(v.begin(),v.end(),a[j]-l[i]);
				query(1,m[*p],max((LL)1,m[a[j]]-1));
				if(Cnt==0)continue;
				switch(f[i]){
					case -1:{val=Min;break;}
					case 0 :{val=Sum/Cnt;break;}
					case 1 :{val=Max;break;}
				}
				if(k[i]==0&&b[j]>val)ans++;
				if(k[i]==1&&b[j]<val)ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}