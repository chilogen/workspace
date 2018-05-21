#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
char c[110][110];
LL a[110][110];
int main(){
	LL i,j,k,o;
	cin>>n>>m;
	for(i=1;i<=n;i++)scanf("%s",c[i]+1);
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)for(j=1;j<=m;j++){
		if(c[i][j]=='.')a[i][j]=0;
		else if(c[i][j]=='*')a[i][j]=-1;
		else a[i][j]=c[i][j]-'0';
	}
	for(i=1;i<=n;i++)for(j=1;j<=m;j++){
		o=0;
		if(a[i][j]==-1)continue;
		for(k=j-1;k<=j+1;k++){
			if(a[i-1][k]==-1)o++;
			if(a[i+1][k]==-1)o++;
		}
		if(a[i][j-1]==-1)o++;
		if(a[i][j+1]==-1)o++;
		if(a[i][j]!=o){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}