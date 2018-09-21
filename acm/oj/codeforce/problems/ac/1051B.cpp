#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL i,l,r;
	cin>>l>>r;
	cout<<"YES\n";
	for(i=l;i<=r;i+=2){
		cout<<i<<" "<<i+1<<endl;
	}
	return 0;
}