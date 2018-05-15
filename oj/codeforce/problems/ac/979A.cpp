#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
int main(){
	cin>>n;
	n++;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(n%2==0)cout<<n/2<<endl;
	else cout<<n<<endl;
	return 0;
}