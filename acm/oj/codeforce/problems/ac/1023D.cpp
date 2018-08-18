#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,q;
LL vis[200010]={0},a[200010];

struct SparseTable{
//array indentity from 0 to size-1
	LL **ST;
	LL num,slog;
	SparseTable(){ST=NULL;}
	SparseTable(LL size){init(size);}
	void init(LL size){
		LL i;
		num=size;

		//2^x<=size<2^(x+1)
		slog=floor(log(size)/log(2));

		
		ST=new LL*[size];
		for(i=0;i<size;i++)ST[i]=new LL[slog];
	}
	void solve(LL *v){
		LL i,j;
		for(i=0;i<num;i++)ST[i][0]=v[i];

		for(i=1;i<=slog;i++){
			for(j=0;j<num;j++){
				if(j+(1ll<<(i-1))>=num)break;
				ST[j][i]=cmp(ST[j][i-1],ST[j+(1ll<<(i-1))][i-1]);
			}
		}
	}
	LL cmp(LL x,LL y){return min(x,y);}
	LL RMQ(LL s,LL t){
		if(s>t)return q;
		LL qlog=floor(log(t-s+1)/log(2));
		return cmp(ST[s][qlog],ST[t+1-(1ll<<qlog)][qlog]);
	}
}ss;


bool check(){
	LL i,k;
	for(i=1;i<=n;i++){
		if(vis[a[i]]!=-1){
			k=ss.RMQ(vis[a[i]]+1,i-1);
			if(k<a[i])return false;
		}
		vis[a[i]]=i;
	}
	return true;
}
void solve(){
	LL i,j=-1,ma=0;
	memset(vis,-1,sizeof(vis));
	for(i=1,a[0]=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		if(a[i]==0){
			j=i;
			a[i]=a[i-1];
		}
	}
	if(ma<q){
		if(j==-1){
			cout<<"NO\n";
			return ;
		}
		a[j]=q;
	}
	ss.init(n+1);
	ss.solve(a);
	if(!check()){
		cout<<"NO\n";
		return ;
	}
	cout<<"YES\n";
	for(i=1;i<=n;i++)cout<<a[i]<<" ";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	solve();
	return 0;
	
}