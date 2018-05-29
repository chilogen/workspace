#include <bits/stdc++.h>
using namespace std;
int row[2010]={0},colume[2010]={0},n,m,a[2010][2010];
int main(){
	ios::sync_with_stdio(false);
	int i,j;
	string s;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>s;
		for(j=0;j<m;j++){
			if(s[j]=='1')	colume[j]++;
			a[i][j]=s[j]-'0';
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(colume[j]-a[i][j]==0)break;
		}
		if(j==m){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}