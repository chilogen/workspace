#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=20010;
LL fat[maxn],q[5010][3].use[maxn],p[maxn];
LL getfat(LL x){
	if(x==fat[x])return x;
	return fat[x]=getfat(fat[x]);
}
vector<int>ans;
int main(){
	LL i,j,t,n,k,kase=1;
	char cmd;
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>k;
		ans.clear();
		for(i=1;i<=n;i++)cin>>p[i];
		memset(use,0,sizeof(use));
		for(i=0;i<k;i++){
			cin>>cmd;
			if(cmd=='C'){
				q[i][0]=0;
				cin>>q[i][1];
				use[q[i][1]]=1;
			}
			else{
				q[i][0]=1;
				cin>>q[i][1]>>q[i][2];
			}
		}
		for(i=1;i<=n;i++){
			if(use[i]||p[i]==0)continue;
			fat[i]=getfat(p[i]);
		}
		for(i=k-1;i>=0;i--){
			if(q[i][0]==0){
				j=q[i][1];
				k=getfat(p[j]);
				fat[j]=k;
			}
			else{
				j=getfat(q[i][1]);
				k=getfat(q[i][2]);
				if(j==k)
					
			}
		}
	}
}