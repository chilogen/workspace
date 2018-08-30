#include <bits/stdc++.h>
using namespace std;
typedef long double ldd;
typedef long long LL;
const ldd pi=acos(-1);
LL n,T;
ldd k,r,d,a,ans,theta,alpha;
ldd area1,area2;
void print(ldd x){
	cout<<setprecision(5)<<fixed;
	cout<<x<<endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("glorious.in","r",stdin);
	LL i,k,kase=1;
	cin>>T;
	while(T--){
		cin>>n>>r>>k;
		cout<<"Case "<<kase++<<": ";
		ans=0;
		theta=2*pi/k;
		alpha=theta/2.0;
		for(i=0;i<n;i++){
			d=r/cos(alpha);
			a=sqrt(d*d-r*r);
			area1=pi*r*r;
			area2=a*r*k;
			ans+=(area2-area1);
			r=d;
		}
		print(ans);
	}
	return 0;
}