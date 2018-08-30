#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;

map<LL,LL>ma;
vector<LL>v;
LL a[100010],cnt[100010],q[100010];
void solve(){
	scanf("%lld%lld",&n,&m);
	ma.clear();v.clear();
	memset(cnt,0,sizeof(cnt));
	LL i,j,k,l;
	for(i=0;i<n;i++)scanf("%lld",&a[i]);
	for(i=0;i<m;i++){
		scanf("%lld",&q[i]);
		v.push_back(q[i]);
	}
	sort(v.begin(),v.end());
	vector<LL>::iterator it=unique(v.begin(),v.end());
	v.resize(it-v.begin());k=v.size();
	for(i=0;i<k;i++)ma[v[i]]=i+1;
	for(i=0;i<n;i++){
		k=a[i];
		l=ma[k];
		if(l!=0)cnt[l]++;
		for(j=i+1;j<n;j++){
			k=__gcd(k,a[j]);
			l=ma[k];
			if(k==1){
				cnt[l]+=(n-j);
				break;
			}
			cnt[l]++;
		}
	}
	for(i=0;i<m;i++){
		j=ma[q[i]];
		printf("%lld ",cnt[j]);
	}
}

int main(){
	LL t;
	scanf("%lld",&t);
	while(t--)solve();
	return 0;
}