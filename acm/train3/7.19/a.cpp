#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
map<string,LL>m;
LL n;
int main(){
	LL i,j=0;
	cin>>n;
	string s1,s2;
	for(i=0;i<n&&j<12;i++){
		cin>>s1>>s2;
		if(m[s1]==0){
			m[s1]=1;
			j++;
			cout<<s1<<" "<<s2<<endl;
		}
	}
	return 0;
}