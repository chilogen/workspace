#include <bits/stdc++.h>
using namespace std;
int l,r,a,ans;
int main(){
	cin>>l>>r>>a;
	int i,j;
	i=min(l,r);j=max(l,r);
	l=i;r=j;
	i=r-l;
	if(i<=a){
		a-=i;
		ans=2*r+a-a%2;
		cout<<ans<<endl;
		return 0;
	}
	else {
		ans=2*(l+a);
		cout<<ans<<endl;
	}
	return 0;
}