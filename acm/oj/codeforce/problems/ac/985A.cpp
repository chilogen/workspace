#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,p[100],k;
LL getans(LL o){
	LL ans=0,i,j=o;
	for(i=0;i<k;i++,j+=2){
		ans+=abs(p[i]-j);
	}
	return ans;
}
int main(){
	LL i;
	cin>>n;
	k=n/2;
	for(i=0;i<k;i++)cin>>p[i];
	sort(p,p+k);
	cout<<min(getans(1),getans(2))<<endl;
	return 0;
}