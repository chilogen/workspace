#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool cmp(LL i,LL j){
	return i>j;
}
int main(){
	vector<LL>v;
	LL suma=0,sumb=0,n,i,j;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j;
		v.push_back(j);
	}
	sort(v.begin(),v.end(),cmp);
	for(i=0;i<n;i++){
		if(i%2==0)suma+=v[i];
		else sumb+=v[i];
	}
	cout<<suma-sumb<<endl;
	return 0;
}