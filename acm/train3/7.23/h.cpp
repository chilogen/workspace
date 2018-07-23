#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7,maxn=1010;
LL ans[2][maxn];
LL **pa,**pb,**pc,*pr;
LL n;
void randmatrix(){
	LL i;
	for(i=0;i<n;i++)pr[i]=rand()%997+1;
}
void mul(LL a[],LL **b,LL c[]){
	LL i,j;
	memset(c,0,sizeof(LL)*n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			c[i]+=a[j]*b[j][i];
			c[i]%=mod;
		}
	}
}
bool equ(){
	LL i;
	for(i=0;i<n;i++)if(ans[0][i]!=ans[1][i])return false;
	return true;
}
void rr(LL **a){
	LL i,j;
	for(i=0;i<n;i++)for(j=0;j<n;j++)
		cin>>a[i][j];
}
int main(){
	LL i;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	pa=new LL*[n];pb=new LL*[n];pc=new LL*[n];pr=new LL[n];
	for(i=0;i<n;i++){
		pa[i]=new LL[n];
		pb[i]=new LL[n];
		pc[i]=new LL[n];
	}
	rr(pa);rr(pb);rr(pc);
	for(i=0;i<1;i++){
		randmatrix();
		mul(pr,pa,ans[0]);
		mul(ans[0],pb,ans[1]);
		mul(pr,pc,ans[0]);
		if(!equ()){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}