#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL>v;
int main()
{
	LL i,j,k,n,ans;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j;
		v.push_back(j);
	}
	sort(v.begin(),v.end());
	k=v[0]-1;
	for(i=0;i<n;i++){
		if(v[i]>k){
			k=v[i];
			if(((int)sqrt(k))*((int)sqrt(k))!=k)	ans=k;
		}
	}
	cout<<ans<<endl;
	return 0;
}