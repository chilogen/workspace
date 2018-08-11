#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,q,x;
int main(){
	LL i,j,k,mid;
	cin>>n>>q;
	mid=(n+n%2)>>1;
	mid=2*mid-1;
	while(q--){
		cin>>x;
		if(x<=mid&&(x+1)%2==0){
			cout<<(x+1)/2<<endl;
			continue;
		}
		i=x/2-1;
		j=n-x;
		k=i+j+1;
		x+=k;
		k=k>>1;
		while((x+1)%2!=0){
			x+=(k);
			k=k>>1;
		}
		cout<<(x+1)/2<<endl;
	}
	return 0;
}