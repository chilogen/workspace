#include <bits/stdc++.h>
using namespace std;
int n,a[4][101][101],ans=1000*1000;
int order[4]={0,1,2,3},board[300][300];
int getans(){
	int i,j,k,a1=0,a2=0;
	for(i=0;i<n;i++)for(j=0;j<n;j++)board[i][j]=a[order[0]][i][j];
	for(i=0;i<n;i++)for(j=n;j<2*n;j++)board[i][j]=a[order[1]][i][j-n];
	for(i=n;i<2*n;i++)for(j=0;j<n;j++)board[i][j]=a[order[2]][i-n][j];
	for(i=n;i<2*n;i++)for(j=n;j<2*n;j++)board[i][j]=a[order[3]][i-n][j-n];
	for(i=0;i<2*n;i++){
		k=i%2;
		for(j=0;j<2*n;j++){
			if(board[i][j]!=k)a2++;
			k=!k;
		}
	}
	for(i=0;i<2*n;i++){
		k=(i+1)%2;
		for(j=0;j<2*n;j++){
			if(board[i][j]!=k)a1++;
			k=!k;
		}
	}
	return min(a1,a2);
}
int main(){
	int i,j,k;
	char c;
	cin>>n;
	for(i=0;i<4;i++){
		for(j=0;j<n;j++)for(k=0;k<n;k++){
			while(cin>>c){
				if(c>='0'&&c<='9')break;
			}
			a[i][j][k]=c-'0';
		}
	}
	do{
		ans=min(ans,getans());
	}while(next_permutation(order,order+4));
	cout<<ans<<endl;
	return 0;
}