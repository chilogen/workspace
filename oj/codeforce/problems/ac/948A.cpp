#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char c[510][510];
int n,m;
int main(){
	int i,j,k,l;
	int x[]={0,0,1,-1},y[]={1,-1,0,0},tx,ty;
	cin>>n>>m;
	for(i=1;i<=n;i++)scanf("%s",&(c[i][1]));
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(c[i][j]=='W'){
				for(k=0;k<4;k++){
					tx=i+x[k];
					ty=j+y[k];
					if(c[tx][ty]=='S'){
						cout<<"No"<<endl;
						return 0;
					}
					if(c[tx][ty]=='.')c[tx][ty]='D';
				}
			}
		}
	}
	cout<<"Yes"<<endl;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)cout<<c[i][j];
		cout<<endl;
	}
	return 0;
}