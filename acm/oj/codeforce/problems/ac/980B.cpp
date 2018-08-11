#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k,i,j,l;
	char c[4][100];
	for(i=0;i<4;i++)for(j=0;j<100;j++)c[i][j]='.';
	cin>>n>>k;
	if(k%2==0&&k!=0){
		i=n/2;
		c[1][i]=c[2][i]='#';
		k-=2;
		for(j=1;k>0;j++){
			for(l=1;l<=2&&k>0;l++){
				c[l][i-j]=c[l][i+j]='#';
				k-=2;
			}
		}
	}
	if(k%2==1){
		i=n/2;
		c[2][i]='#';
		k--;
		for(j=1;k>0;j++){
			for(l=1;l<=2&&k>0;l++){
				c[l][i-j]=c[l][i+j]='#';
				k-=2;
			}
		}
	}
	cout<<"YES\n";
	for(i=0;i<4;i++){
		for(j=0;j<n;j++)cout<<c[i][j];
		cout<<endl;
	}
	return 0;
}