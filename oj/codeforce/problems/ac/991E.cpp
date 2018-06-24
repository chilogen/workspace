#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL p[20],ans=0,cnt[10]={0},n,tcnt[10]={0};
void dfs(LL x,LL t,LL y){
	if(x==10){
		LL i,b=p[t];
		for(i=0;i<10;i++)b=b/p[tcnt[i]];
		ans+=b;
		return ;
	}
	LL i;
	if(cnt[x]==0){tcnt[x]=0;dfs(x+1,t,y);}
	else{
		if(y==x)i=0;
		else i=1;
		for(;i<=cnt[x];i++){
			tcnt[x]=i;
			dfs(x+1,t+i,y);
		}
	}
}
int main(){
	cin>>n;
	LL i,j,k=n;
	p[0]=p[1]=1;
	for(i=2;i<20;i++)p[i]=p[i-1]*i;
	while(k){
		j=k%10;
		cnt[j]++;
		k/=10;
	}
	for(i=1;i<10;i++){
		if(cnt[i]==0)continue;
		cnt[i]--;
		dfs(0,0,i);
		cnt[i]++;
	}
	cout<<ans<<endl;
	return 0;
}