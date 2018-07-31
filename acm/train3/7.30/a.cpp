#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL s,g,a,b,sab;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s>>g;
	if(s%g!=0){
		cout<<-1<<endl;
		return 0;
	}
	sab=s/g;
	if(sab<2){
		cout<<-1<<endl;
		return 0;
	}
	b=g;a=g*(sab-1);
	cout<<a<<" "<<b<<endl;
	return 0;
}