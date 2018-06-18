#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10;
const LL inf=1e10;
LL n,m,a[maxn],b[maxn],c[maxn],p[maxn];
vector<LL>ans;
void kmp(){
	LL i,j;
	p[0]=p[1]=0;
	for(i=1;i<m-1;i++){
		j=p[i];
		while(j&&b[i]!=b[j])j=p[j];
		if(b[i]==b[j])p[i+1]=j+1;
		else p[i+1]=0;
	}
	for(i=0,j=0;i<n-1;i++){
		while(j&&a[i]!=b[j])j=p[j];
		if(a[i]==b[j])j++;
		if(j==m-1)ans.push_back(i-m+2);
	}
}
int main(){
	LL i,k;
	ios::sync_with_stdio(false);
	cin>>n>>m>>c[0];
	for(i=1;i<n;i++){
		cin>>c[i];
		a[i-1]=c[i]-c[i-1];
	}
	cin>>c[0];
	for(i=1;i<m;i++){
		cin>>c[i];
		b[i-1]=c[i-1]-c[i];
	}
	b[i-1]=inf;
	kmp();
	sort(ans.begin(),ans.end());
	k=ans.size();
	cout<<k<<endl;
	for(i=0;i<k;i++)cout<<ans[i]<<" ";
	return 0;
}