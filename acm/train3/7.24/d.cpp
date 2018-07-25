#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<pair<LL,LL> >a,b;
LL t,n,m,x,y,ans;
int main(){
	LL i,j,k,l,r,as,bs,d;
	pair<LL,LL>tp;
	cin>>t;
	while(t--){
		a.clear();
		b.clear();
		ans=0;
		cin>>n>>m>>x>>y;
		for(i=0;i<x;i++){
			cin>>l>>r;
			a.push_back(make_pair(l,r));
		}
		for(i=0;i<y;i++){
			cin>>l>>r;
			b.push_back(make_pair(l,r));
		}
		j=k=0;as=a.size();bs=b.size();
		while(j<as&&k<bs){
			if(a[j].second<b[k].first){j++;continue;}
			if(b[k].second<a[j].first){k++;continue;}
			l=max(a[j].first,b[k].first);
			r=min(a[j].second,b[k].second);
			d=r;
			r=min(n,r);
			i=(r-l+1);
			if(i>=m)ans+=(i-m+1);
			if(d!=r)break;
			if(a[j].second<b[k].second)j++;
			else k++;
		}
		cout<<ans<<endl;
	}
	return 0;
}