#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL a,b,c,n,k;
	cin>>a>>b>>c>>n;
	if(c>a||c>b){
		cout<<-1<<endl;
		return 0;
	}
	k=a+b-c;
	k=n-k;
	if(k<1)cout<<-1<<endl;
	else cout<<k<<endl;
	return 0;
}