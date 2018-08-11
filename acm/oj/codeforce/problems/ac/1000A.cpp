#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
string s;
LL cnt[2][9];
map<string,LL>m;
int main(){
	LL i,j;
	string ts[]={"s","M","L","XS","XL","XXL","XXS","XXXL","XXXS"};
	for(i=0;i<9;i++)m[ts[i]]=i;
	cin>>n;
	
	for(i=0;i<2;i++)for(j=0;j<n;j++){
		cin>>s;
		cnt[i][m[s]]++;
	}

	for(i=0;i<9;i++){
		j=min(cnt[0][i],cnt[1][i]);
		cnt[0][i]-=j;
		cnt[1][i]-=j;
	}

	for(i=j=0;i<9;i++)j+=cnt[0][i];
	cout<<j<<endl;
	return 0;
}