#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mma=1e7;
struct Prime{
	LL maxn;
	vector<int>list;
	bool vis[mma];
	Prime(int x):maxn(x){}
	void init(){
		LL i;
		memset(vis,0,sizeof(vis));
		for(i=2;i<maxn;i++){
			if(!vis[i])list.push_back(i);
			vector<int>::iterator p=list.begin();
			while(p!=list.end()&&i*(*p)<maxn){
				vis[i*(*p)]=1;
				if(i%(*p)==0)break;
				p++;
			}
		}
	}
}a(10000000);
LL pmod(LL x,LL y,LL mod){
	LL j=x,a=1;
	while(y){
		if(y&1){
			a*=j;
			a%=mod;
		}
		y>>=1;
		j*=j;
		j%=mod;
	}
	return a;
}
LL p;
bool check(LL x,LL y,LL mod){
	if(pmod(x,y,mod)!=1)return false;
	if(pmod(x,1,mod)==1)return false;
	LL i;
	for(i=2;i<=p+1;i++){
	//for(i=y-1;i>=p;i--){
		//if(pmod(x,i,mod)==1)return false;
		
		if(y%i!=0)continue;
		if(pmod(x,i,mod)==1)return false;
		if(pmod(x,y/i,mod)==1)return false;
		
	}
	return true;
}
int main(){
	a.init();
	vector<LL>ans;
	LL q,n,i;
	cin>>q>>n;
	p=sqrt(n);
	p=max(1ll,p);
	for(i=0;i<664579;i++){
		if(a.list[i]<n)continue;
		if(check(q,n,a.list[i]))ans.push_back(a.list[i]);
	}
	cout<<ans.size()<<endl;
	for(i=0;i<(LL)ans.size();i++)cout<<ans[i]<<" ";
	return 0;
}