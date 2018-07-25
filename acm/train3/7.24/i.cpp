#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10;
LL t,n,belong[maxn];
LL sum;
string s;

int main(){
	LL i;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>s;
		sum=(1+n)*n/2;
		if(sum%2!=0){cout<<-1<<endl;continue;}
		sum/=2;
		for(i=n-1;i>=0;i--){
			if(sum<i+1){
				if(s[i]=='1')belong[i]=4;
				else belong[i]=2;
				continue;
			}
			sum-=(i+1);
			if(s[i]=='1')belong[i]=3;
			else belong[i]=1;
		}
		if(sum!=0){cout<<-1<<endl;continue;}
		for(i=0;i<n;i++){
			cout<<belong[i];
		}
		cout<<endl;
	}
	return 0;
}