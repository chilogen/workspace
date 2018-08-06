#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
void rotate(LL x,LL y){
	LL i,j,k=0;
	for(i=x;i<y;i++){
		k+=s[i]-'A';
	}
	for(i=x;i<y;i++){
		j=(s[i]+k)%26;
		s[i]='A'+j;
	}
}
void merge(){
	LL i,j,k;
	i=0;j=s.length()/2;
	for(i=0;i<(LL)s.length()/2;i++,j++){
		k=(s[i]+s[j])%26;
		s[i]='A'+k;
	}
	for(i=0;i<(LL)s.length()/2;i++)cout<<s[i];
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>s;
	rotate(0,s.length()/2);
	rotate(s.length()/2,s.length());
	merge();
	return 0;
}