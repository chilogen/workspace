#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e5+10;
string s[maxn];
pair<LL,LL>p[maxn];
LL ans=0;
LL n,m;
int main(){
	LL i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)cin>>s[i];
	cin>>m;
	k=0;
	for(i=1;i<=m;i++){
		cin>>p[i].first>>p[i].second;
		if(p[i].first==1)k=i;
	}
	if(k==0){
		cout<<s[1]<<endl;
		return 0;
	}
	for(i=k;i>=0;i--){
		ans++;
		j=p[i].second;
		for(;i>=0;i--)if(p[i].first==j)break;
		i++;
	}
	for(i=0;i<ans;i++)cout<<"I_love_";
	cout<<s[j]<<endl;
	return 0;
}