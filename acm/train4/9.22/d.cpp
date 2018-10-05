#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e6+10;
LL a[2*maxn],b[2*maxn],p1,p2,n,c;

void solve(){
	LL i,p1,p2;
	cin>>n>>c;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)cin>>b[i];
	for(i=n+1;i<=2*n;i++){
		a[i]=a[i-n];
		b[i]=b[i-n];
	}
	p1=p2=1;
	c+=a[p1];
	while(p2<=2*n&&p2-p1<n){
		while(c-b[p2]<0){
			if(p1<p2){
				c+=b[p1];
				c-=a[p1];
				p1++;
			}
			else{
				c-=a[p1];
				p1++;
				p2++;
				c+=a[p1];
			}
		}
		c-=b[p2];
		p2++;
		c+=a[p2];
	}
	if(p1>n)cout<<-1<<endl;
	else cout<<p1<<endl;
}

int main(){
	LL t;
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}