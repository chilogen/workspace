#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
hash<string>ha;
set<LL>s;
LL n;
int main(){
	string str;
	LL i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>str;
		s.insert(ha(str));
	}
	cout<<s.size()<<endl;
	return 0;
}