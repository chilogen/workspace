#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,c,a[100010],b[100010],cnt[3]={0};
vector<LL>v;
map<LL,LL>m1,m2;
bool check(LL x,LL c){
	LL j,cnt=0;
	memcpy(b,a,sizeof(b));
	for(j=x;j>0&&cnt<=3;j--){
		if(b[j]-b[j-1]!=c){
			cnt++;
			b[j-1]=b[j]-c;
		}
	}
	for(j=x+1;j<n&&cnt<=3;j++){
		if(b[j]-b[j-1]!=c){
			cnt++;
			b[j]=b[j-1]+c;
		}
	}
	return cnt<=3;
}
void solve(LL x){
	LL i;
	for(i=x;i>0;i--){
		if(a[i]-a[i-1]==c&&a[i+1]-a[i]==c)continue;
		if(a[i+1]-a[i]!=c)a[i+1]=a[i]+c;
		else if(a[i]-a[i-1]!=c)a[i-1]=a[i]-c;
	}
	for(i=x;i<n-1;i++){
		if(a[i]-a[i-1]==c&&a[i+1]-a[i]==c)continue;
		if(a[i+1]-a[i]!=c)a[i+1]=a[i]+c;
		else if(a[i]-a[i-1]!=c)a[i-1]=a[i]-c;
	}
}
LL diff(LL a,LL b,LL c){
	LL i;
	for(i=1;i<n;i++){
		if(i==a||i-1==a)continue;
		if(i==b||i-1==b)continue;
		if(i==c||i-1==c)continue;
		return i;
	}
	return 0;
}
void solve1(){
	LL i,j,k,l;
	if(n<=4){
		for(i=0;i<n;i++)cout<<a[1]<<" ";
		return ;
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=j+1;k<n;k++){
				l=diff(i,j,k);
				if(check(l,a[l]-a[l-1])){
					for(l=0;l<n;l++)cout<<b[l]<<" ";
					return ;
				}
			}
		}
	}
}
int main(){
	LL i,j,k,l;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	if(n<=15){
		solve1();
		return 0;
	}
	for(i=1;i<n;i++){
		j=a[i]-a[i-1];
		v.push_back(j);
	}
	sort(v.begin(),v.end());
	vector<LL>::iterator p;
	p=unique(v.begin(),v.end());
	v.resize(p-v.begin());
	for(i=0;i<(LL)v.size();i++){
		m1[v[i]]=i;
		m2[i]=v[i];
	}
	for(i=1;i<n;i++){
		j=a[i]-a[i-1];
		cnt[m1[j]]++;
	}
	for(i=0,k=0;i<(LL)v.size();i++){
		if(cnt[i]>k){
			k=cnt[i];
			c=m2[i];
			l=i;
		}
	}
	if(cnt[l]==1){
		for(i=1;i<n;i++)if(a[i]-a[i-1]==c)break;
		solve(i);
	}
	else{
		for(i=1;i<n-1;i++)if(a[i+1]-a[i]==c&&a[i]-a[i-1]==c)break;
		solve(i);
	}
	for(i=0;i<n;i++)cout<<a[i]<<" ";
	return 0;
}