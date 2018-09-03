#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k;
int main(){
	cin>>n;
	k=0;
	while(n){
		k++;
		n>>=1;
	}
	cout<<k<<endl;
	return 0;
}