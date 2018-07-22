#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[200][200],ans=0,n,m;
string s[200];
LL x[]={1,-1,0,0},y[]={0,0,1,-1};
int main(){
	LL i,j,k,tx,ty;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	memset(a,0,sizeof(a));
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>s[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			a[i][j]=s[i-1][j-1]-'0';
			ans+=min((LL)1,a[i][j])*2;
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			for(k=0;k<4;k++){
				tx=x[k]+i;
				ty=y[k]+j;
				ans+=max((LL)0,a[i][j]-a[tx][ty]);
			}
	cout<<ans<<endl;
	return 0;
}