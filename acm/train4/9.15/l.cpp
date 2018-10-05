#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;

struct matrix{
	LL a[9][9];
	void times(matrix x){
		LL i,j,k,m;
		LL b[9][9];
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				m=0;
				for(k=0;k<9;k++){
					m+=(a[i][k]*x.a[k][j]);
					m%=mod;
				}
				b[i][j]=m;
			}
		}
		memcpy(a,b,sizeof(a));
	}
	void initone(){
		LL i;
		memset(a,0,sizeof(a));
		for(i=0;i<9;i++)a[i][i]=1;
	}
	void init1(){
		LL b[9][9]={{0,0,0,1,0,0,1,0,0}, \
					{1,0,0,1,0,0,1,0,0}, \
					{1,0,0,1,0,0,0,0,0}, \
					{0,1,0,0,1,0,0,1,0}, \
					{0,1,0,0,0,0,0,1,0}, \
					{0,1,0,0,1,0,0,0,0}, \
					{0,0,1,0,0,0,0,0,1}, \
					{0,0,0,0,0,1,0,0,1}, \
					{0,0,1,0,0,1,0,0,0}};
		memcpy(a,b,sizeof(a));
	}
	void init2(){
		LL i;
		memset(a,0,sizeof(a));
		for(i=0;i<9;i++)a[i][0]=1;
	}
}y;
void mpow(matrix &m,LL x){
	matrix ans,tmp=m;
	ans.initone();
	while(x){
		if(x&1)ans.times(tmp);
		x>>=1;
		tmp.times(tmp);
	}
	m=ans;
}
void solve(){
	LL i,n,ans=0;
	cin>>n;
	if(n==1){
		cout<<3<<endl;
		return;
	}
	matrix x;
	x.init1();
	mpow(x,n-2);
	x.times(y);
	for(i=0;i<9;i++)ans+=x.a[i][0];
	cout<<ans%mod<<endl;
}
int main(){
	LL t;
	y.init2();
	cin>>t;
	while(t--)solve();
	return 0;
}