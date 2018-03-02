#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,a;
int main(){
	LL i,j,num=0,t,an=-1;
	cin>>n>>k;
	if(n==0){
		cout<<"1 0\n";
		return 0;
	}
	for(i=0;i<k;i++){
		cin>>a;
		if(a>n)	continue;
		j=n-n%a;
		if(j>num){
			num=j;
			t=i+1;
			an=a;
		}
	}
	if(an==-1)cout<<"1 0\n";
	else cout<<t<<" "<<n/an<<endl;
	return 0;
}