#include <bits/stdc++.h>
using namespace std;
int r[23],n,m,success,ans=99999;
inline void connect(int x,int y){
	r[x]|=(1<<y);
	r[y]|=(1<<x);
}
inline bool check(int *a){
	int i;
	for(i=1;i<=n;i++)if(a[i]!=success)break;
	return i==n+1;
}
inline void choose(int x,int *a,int *b){
	int i,j;
	memset(a,0,sizeof(int)*23);
	for(i=1;i<=n;i++)a[i]+=(1<<i);
	memcpy(a,b,sizeof(int)*23);
	for(i=0,j=b[x];j!=0;j>>=1,i++)if(j&1)a[i]|=b[x];
}
inline bool equ(int *a,int *b){
	int i;
	for(i=1;i<=n;i++)if(b[i]!=a[i])break;
	return i==n+1;
}
void dfs(int *a,int d,int x){
	if(x>n)return;
	if(check(a)){
		ans=min(ans,d);
		return ;
	}
	int tmp[23];
	dfs(a,d,x+1);
	if(x+1>n)return;
	choose(x+1,tmp,a);
	if(equ(tmp,a))return;
	dfs(tmp,d+1,x+1);
}
int main(){
	cin>>n>>m;
	success=(1<<(n+1))-2;
	int i,j,k,tmp[23];
	memset(r,0,sizeof(r));
	for(i=1;i<=n;i++)r[i]+=(1<<i);
	for(i=0;i<m;i++){
		cin>>j>>k;
		connect(j,k);
	}
	dfs(r,0,1);
	choose(1,tmp,r);
	dfs(tmp,1,1);
	cout<<ans<<endl;
	return 0;
}