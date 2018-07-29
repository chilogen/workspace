#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL t,q,cnt[10];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	LL i;
	cin>>t;
	while(t--){
		cin>>q;
		if(q==1){cout<<1<<endl;continue;}
		if(q==0){cout<<10<<endl;continue;}
		memset(cnt,0,sizeof(cnt));
		for(i=9;i>=2&&q!=1;i--){
			while(q%i==0&&q!=1){
				cnt[i]++;
				q/=i;
			}
		}
		if(q>9){cout<<-1<<endl;continue;}
		for(i=2;i<=9;i++){
			while(cnt[i]){
				cout<<i;
				cnt[i]--;
			}
		}
		cout<<endl;
	}
	return 0;
}