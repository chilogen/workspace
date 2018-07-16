#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=249500,bound1=1e17,bound2=1e9;
LL k;
vector<LL>prime,fib,pk;
int vis[maxn]={0};
int main(){
	LL i,j,l;
	for(i=2;i<maxn;i++){
		if(!vis[i])prime.push_back(i);
		for(j=0,l=prime.size();j<l&&i*prime[j]<maxn;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	fib.push_back(1);fib.push_back(1);pk.push_back(0);pk.push_back(0);
	for(i=2;i<maxn;i++){
		if(pk[i-1]==1)j=10;
		else j=1; 
		j=fib[i-1]+fib[i-2]/j;
		if(j>bound1){
			k=1;
			j/=10;
		}
		else k=0;
		fib.push_back(j);
		pk.push_back(k);
	}
	while(scanf("%lld",&k)!=EOF){
		j=fib[prime[k-1]-1];
		while(j>bound2)j/=10;
		cout<<j<<endl;
	}
	return 0;
}