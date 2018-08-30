#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int andr[2][maxn],orr[2][maxn],xorr[2][maxn];
int n,q;
int a[maxn];
int main(){
	int i,j,k;
	while(scanf("%d%d",&n,&q)!=EOF){
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		andr[0][1]=orr[0][1]=xorr[0][1]=a[1];
		andr[1][n]=orr[1][n]=xorr[1][n]=a[n];
		for(i=2;i<=n;i++){
			andr[0][i]=andr[0][i-1]&a[i];
			orr[0][i]=orr[0][i-1]|a[i];
			xorr[0][i]=xorr[0][i-1]^a[i];
		}
		for(i=n-1;i>=1;i--){
			andr[1][i]=andr[1][i+1]&a[i];
			orr[1][i]=orr[1][i+1]|a[i];
			xorr[1][i]=xorr[1][i+1]^a[i];
		}
		for(i=0;i<q;i++){
			scanf("%d",&j);
				if(j==1){
					cout<<andr[1][2]<<" "<<orr[1][2]<<" "<<xorr[1][2]<<endl;
				}
				else if(j==n){
					cout<<andr[0][n-1]<<" "<<orr[0][n-1]<<" "<<xorr[0][n-1]<<endl;
				}
				else{
					k=andr[0][j-1]&andr[1][j+1];
					cout<<k<<" ";
					k=orr[0][j-1]|orr[1][j+1];
					cout<<k<<" ";
					k=xorr[0][j-1]^xorr[1][j+1];
					cout<<k<<endl;
				}
		}
	}
	return 0;
}
