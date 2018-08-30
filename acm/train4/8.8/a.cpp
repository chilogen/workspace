#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL m,k,j=0;
	long double a=log(2)/log(10);
	while(scanf("%lld",&k)!=EOF){
		cout<<"Case #"<<++j<<": ";
		m=a*k;
		cout<<m<<endl;
	}
	return 0;
}