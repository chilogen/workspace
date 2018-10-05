#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

stack<LL>pile;
LL n,m,a[20000],win;

inline LL nex(LL x,LL mod){
	x=(x+1)%mod;
	if(x==0)return 1;
	return x;
}

struct player{
	LL cnt[15],hand;
	LL play(LL x){
		if(cnt[x+1]!=0){
			cnt[x+1]--;
			hand--;
			return x+1;
		}
		if(x!=2&&cnt[2]!=0){
			cnt[2]--;
			hand--;
			return 2;
		}
		return x;
	}

	LL play1(){
		LL i;
		for(i=3;i<=13;i++)if(cnt[i]!=0){
			cnt[i]--;
			hand--;
			return i;
		}
		if(cnt[1]!=0){
			cnt[1]--;
			hand--;
			return 1;
		}
		if(cnt[2]!=0){
			cnt[2]--;
			hand--;
			return 2;
		}
		return -1;
	}

	void pick(){
		if(pile.empty())return;
		cnt[pile.top()]++;
		pile.pop();
		hand++;
	}

	LL sum(){
		LL i,ans=0;
		for(i=1;i<=13;i++)ans+=(i*cnt[i]);
		return ans;
	}

	void init(){
		memset(cnt,0,sizeof(cnt));
		hand=0;
	}
}p[300];

LL round(LL x){
	LL passcnt=0,j,k,l=x;
	k=p[x].play1();
	if(p[x].hand==0){
		win=x;
		return -1;
	}
	while(1){
		x=nex(x,n+1);
		j=p[x].play(k);
		if(p[x].hand==0){
			win=x;
			return -1;
		}
		if(j==k)passcnt++;
		else{
			k=j;
			passcnt=0;
			l=x;
		}
		if(passcnt==n-1){
			for(j=l+1;j!=l;j=nex(j,n+1))p[j].pick();
			return l;
		}
	}
}

void solve(LL Kase){
	cin>>n>>m;
	LL i,j,k;
	while(!pile.empty())pile.pop();
	for(i=0;i<m;i++)cin>>a[i];
	for(i=m-1;i>=0;i--)pile.push(a[i]);
	for(i=0;i<=n;i++)p[i].init();
	for(j=1;j<=n;j++)for(i=0;i<5;i++)p[j].pick();
	k=1;
	while(1){
		j=round(k);
		if(j==-1)break;
		k=j;
	}
	cout<<"Case #"<<Kase<<":\n";
	for(i=1;i<=n;i++){
		if(i==win)cout<<"Winner\n";
		else cout<<p[i].sum()<<endl;
	}
}

int main(){
	LL t,i;
	cin>>t;
	for(i=1;i<=t;i++)solve(i);
	return 0;
}