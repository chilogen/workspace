
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=15000001;
LL cnt[maxn],n,ans,a[300001],GCD,MAX=-1;
bool vis[maxn];
vector<LL>v;

void init(){
	LL i;
	for(i=2;i<maxn;i++){
		if(!vis[i]&&i>GCD&&i<=MAX)v.push_back(i);
		vector<LL>::iterator p=v.begin();
		while(p!=v.end()&&i*(*p)<maxn){
			vis[i*(*p)]=1;
			if(i%(*p)==0)break;
			p++;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie();cout.tie(0);
	LL i,j,k,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		MAX=max(MAX,a[i]);
	}
	GCD=a[0];
	for(i=1;i<n;i++)GCD=__gcd(GCD,a[i]);
	init();
	ans=n;
	j=v.size();
	for(i=0;i<j;i++){
		c=0;
		for(k=v[i];k<maxn;k+=v[i])c+=cnt[k];
		ans=min(ans,n-c);
	}
	if(ans==n)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}