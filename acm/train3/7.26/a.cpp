#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<string>s[26];
string ts;
LL len,cnt=0;
void shift(LL x){
	string t="";
	LL i,j;
	for(i=x;i<len;i++)t+=ts[i];
	for(i=0;i<x;i++)t+=ts[i];
	j=t[0]-'a';
	s[j].push_back(t);
}
void solve(LL x){
	LL i,j,k,l=s[x].size();
	LL tans,ans=0;
	LL count[26];
	for(i=1;i<len;i++){
		tans=0;
		memset(count,0,sizeof(count));
		for(j=0;j<l;j++){
			k=s[x][j][i]-'a';
			count[k]++;
		}
		for(k=0;k<26;k++)if(count[k]==1)tans++;
		ans=max(ans,tans);
	}
	cnt+=ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	LL i;
	cin>>ts;
	len=ts.length();
	for(i=0;i<len;i++)shift(i);
	for(i=0;i<26;i++)solve(i);
	double a=cnt,b=len;
	printf("%.10lf\n",a/b);
	return 0;
}