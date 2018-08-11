#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[15],b[15],ans=9999,k;
LL check(LL f){
	LL i=k-1,j=0,l=1,sum=0;
	bool zero=true;
	while(f){
		if(f&1){
			sum+=(l*a[i]);
			if(a[i]==0)zero=true;
			else zero=false;
			l*=10;
			j++;
		}
		f=f>>1;
		i--;
	}
	i=sqrt(sum);
	if(i*i==sum&&!zero)return k-j;
	else return 9999;
}
void dfs(LL f,LL i){
	if(i==k){ans=min(ans,check(f));return;}
	f=f^(1<<i);
	dfs(f,i+1);
	f=f^(1<<i);
	dfs(f,i+1);
}
int main(){
	string s;
	cin>>s;
	LL i;
	k=s.length();
	for(i=0;i<k;i++)a[i]=s[i]-'0';
	dfs(0,0);
	if(ans>=k)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}