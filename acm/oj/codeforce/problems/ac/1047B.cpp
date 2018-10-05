#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,x,y,b;
int main(){
	LL i;
	cin>>n;
	cin>>x>>y;
	b=y+x;
	for(i=1;i<n;i++){
		cin>>x>>y;
		b=max(b,y+x);
	}
	cout<<b<<endl;
	return 0;
}