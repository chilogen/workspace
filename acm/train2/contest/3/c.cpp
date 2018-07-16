#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL p,n,m,cnt[2][10010]={0};
LL solve(LL x,LL y){
	if(x<y){cnt[0][x]=1;return 1;}
	LL i,j,k,l;
	k=x%y;
	j=solve(x/y,y);
	memset(cnt[1],0,sizeof(cnt[1]));
	cnt[1][k]=j;
	for(i=1;i<=x/y;i++)if(cnt[0][i]){
		j+=(cnt[0][i]*i);
		for(l=1;l<=i;l++)if(l*y+k<10010)
			cnt[1][l*y+k]+=cnt[0][i];
	}
	memcpy(cnt[0],cnt[1],sizeof(cnt[1]));
	return j;
}
int main(){
	LL k;
	cin>>p;
	while(p--){
		cin>>k>>n>>m;
		memset(cnt[0],0,sizeof(cnt[0]));
		cout<<k<<" "<<solve(m,n)<<endl;
	}
}