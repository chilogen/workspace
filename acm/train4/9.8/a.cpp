#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10;
LL n,x,A,B;
bool vis[maxn];
LL a[maxn],mi[maxn],ma[maxn];

LL solve(){
	LL i,k,li,ri,L[2],R[2];
	LL player1=1,player2;
	cin>>n>>x;
	cin>>A>>B;
	for(i=0;i<A;i++){
		cin>>a[i];
		vis[a[i]]=1;
		if(a[i]==1)player1=0;
	}

	vis[0]=vis[1];li=ri=0;
	for(i=k=1;i<=(A+B);i++){
		if(vis[i]==vis[i-1]){
			li++;
			ri+=x;
		}
		else{
			mi[k]=li;
			ma[k]=ri;
			li=1;ri=x;
			k++;
		}
	}
	mi[k]=li;ma[k]=ri;
	L[0]=L[1]=R[0]=R[1]=0;
	
	for(i=1;i<=k;i++){
		player2=!player1;

		li=R[player2]+L[player1]+1;
		ri=L[player2]+R[player1]+ma[i];
		if(li<=n&&ri>=n){
			for(i=0;i<A;i++)vis[a[i]]=0;
			return player1;
		}
		L[player1]+=mi[i];
		R[player1]+=ma[i];
		player1=player2;
	}
	return -1;
}

string player[2]={"Gudako\n","Ritsuka\n"};

int main(){
	LL t,i;
	cin>>t;
	while(t--){
		i=solve();
		cout<<player[i];
	}
	return 0;
}