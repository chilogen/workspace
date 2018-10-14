#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL n,m,k,i,l;
	cin>>n>>m>>k;
	vector<LL>v(n);
	for(i=0;i<n;i++)cin>>v[i];
	reverse(v.begin(),v.end());
	for(i=l=0,m--;i<n;i++){
		if(l+v[i]<=k)l+=v[i];
		else if(m==0)break;
		else{
			l=v[i];
			m--;
		}
	}
	cout<<i<<endl;
	return 0;
}