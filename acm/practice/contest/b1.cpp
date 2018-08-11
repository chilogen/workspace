#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[100010],b[100010];
vector<LL>v;
map<LL,LL>m;
bool solve(LL c){
	LL i,j,cnt=0;
	memcpy(b,a,sizeof(b));
	for(i=1;i<n;i++)if(a[i]-a[i-1]==c)break;
	for(j=i-1;j>0&&cnt<=3;j--){
		if(b[j]-b[j-1]!=c){
			cnt++;
			b[j-1]=b[j]-c;
		}
	}
	for(j=i+1;j<n&&cnt<=3;j++){
		if(b[j]-b[j-1]!=c){
			cnt++;
			b[j]=b[j-1]+c;
		}
	}
	return cnt<=3;
}
int main(){
	LL i,j;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=1;i<n;i++){
		j=a[i]-a[i-1];
		v.push_back(j);
	}
	vector<LL>::iterator it;
	sort(v.begin(),v.end());
	it=unique(v.begin(),v.end());
	v.resize(it-v.begin());
	for(i=0;i<(LL)v.size();i++)m[v[i]]=i;
	for(i=0;i<(LL)v.size();i++)if(solve(v[i]))break;
	for(i=0;i<n;i++)cout<<b[i]<<" ";
	return 0;
}