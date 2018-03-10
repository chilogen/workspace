#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,x[2][100010];
int main(){
	LL i,j,k;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>x[0][i];
	for(i=0;i<m;i++)cin>>x[1][i];
	LL fsize[2]={0},p[2]={-1,-1},ans=0,flag=0;
	while(p[0]<n&&p[1]<m){
		if(fsize[0]==fsize[1]){
			ans++;
			flag=0;
		}
		p[flag]++;
		fsize[flag]+=x[flag][p[flag]];
		if(fsize[flag]>fsize[!flag])flag=!flag;
	}
	cout<<ans-1<<endl;
	return 0;
}