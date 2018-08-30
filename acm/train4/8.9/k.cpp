#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int fail1[maxn],fail2[maxn],n,len;
int cir[maxn];
string patten;
void getfail1(){
	fail1[0]=0;
	int i=0,j=1,k=len;
	while(j<k){
		fail1[j]=i;
		if(patten[i]==patten[j])	i++;
		else	i=0;
		j++;
	}
}
void getfail2(){
	int i,j,k=patten.len;
	fail2[k-1]=0;i=k-1;j=k-2;
	while(j>=0){
		fail2[j]=i;
		if(patten[i]==patten[j])i--;
		else i=k-1;
		j--;
	}
}
bool check(LL x){
	LL i,j,k,l=len;
	for(i=0;i<x;i++)cir[i]=patten[i]-'0';
	
}
int main(){
	int d,l,ans,i;
	while(scanf("%lld",&n)!=EOF){
		cin>>patten;
		len=patten.length();
		ans=maxn;
		getfail1();
		getfail2();
		for(i=0;i<len;i++)if(fail1[i]!=0)break;
		if(check(i))ans=min(ans,i);
		for(i=l-1;i>=0;i--)if(fail2[i]!=0)break;
		i=l-i;
		if(check(i))ans=min(ans,i);
		cout<<ans<<" "<<endl;
	}
	return 0;
}