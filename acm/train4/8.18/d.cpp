#include <bits/stdc++.h>
using namespace std;
int a[510];
string s[510];
vector<int>ans[2];
int n,m,k;
int main(){
	cin>>n>>m>>k;
	int i,j,l;
	bool have=true;
	for(i=0;i<n;i++)cin>>s[i];
	memset(a,0,sizeof(a));l=0;
	for(i=0;i<n&&have;i++){
		for(j=0;j<m&&have;j++){
			if(s[i][j]=='0')continue;
			if(a[j]!=0){
				have=false;
				continue;
			}
			a[j]=1;l++;
		}
		if(l==k){
			memset(a,0,sizeof(a));
			l=0;
			ans[0].push_back(i+1);
		}
		if(l>k)have=false;
	}
	memset(a,0,sizeof(a));l=0;
	for(j=0;j<m&&have;j++){
		for(i=0;i<n&&have;i++){
			if(s[i][j]=='0')continue;
			if(a[i]!=0){
				have=false;
				continue;
			}
			a[i]=1;l++;
		}
		if(l==k){
			memset(a,0,sizeof(a));
			l=0;
			ans[1].push_back(j+1);
		}
		if(l>k)have=false;
	}
	if((int)ans[0].size()!=k||(int)ans[1].size()!=k||!have){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for(i=0;i<k-1;i++)cout<<ans[0][i]<<endl;
	for(i=0;i<k-1;i++)cout<<ans[1][i]<<endl;
	return 0;
}
