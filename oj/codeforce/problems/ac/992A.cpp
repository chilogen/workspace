#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
vector<LL>v;
int main(){
	LL i,j,k=0;
	ios::sync_with_stdio(false);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j;
		if(j==0)k=1;
		v.push_back(j);
	}
	sort(v.begin(),v.end());
	vector<LL>::iterator p=unique(v.begin(),v.end());
	v.resize(p-v.begin());
	cout<<v.size()-k<<endl;
	return 0;
}