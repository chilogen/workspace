#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL Case=0,m,n,p,q;
LL a[30][30],b[30][30],c[30][30];
inline LL getij(LL x,LL y){
	LL i,ans=0;
	for(i=0;i<n;i++)
		ans+=(a[x][i]*b[i][y]);
	return ans;
}
int main(){
	LL i,j;
	cin>>m>>n>>p>>q;
	while(n!=0&&m!=0&&p!=0&&q!=0){
		Case++;
		cout<<"Case #"<<Case<<":\n";
		for(i=0;i<m;i++)for(j=0;j<n;j++)cin>>a[i][j];
		for(i=0;i<p;i++)for(j=0;j<q;j++)cin>>b[i][j];
		if(n!=p){
			cout<<"undefined\n";
			cin>>m>>n>>p>>q;
			continue;
		}
		for(i=0;i<m;i++)for(j=0;j<q;j++)c[i][j]=getij(i,j);
		for(i=0;i<m;i++){
			cout<<"| ";
			for(j=0;j<q;j++)cout<<c[i][j]<<" ";
			cout<<"|\n";
		}
		cin>>m>>n>>p>>q;
	}
	return 0;
}