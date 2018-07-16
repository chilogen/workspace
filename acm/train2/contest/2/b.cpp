#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
set<LL>s;
LL n;
string str;
inline void add(string st){
	LL i,k,l=st.length();
	LL a[10]={0};
	for(i=0;i<l;i++)a[st[i]-'0']=1;
	for(i=1,k=0;i<10;i++){
		if(a[i]){
			k=k*10;
			k+=i;
		}
	}
	s.insert(k);
}
int main(){
	LL i;
	while(cin>>n){
		s.clear();
		for(i=0;i<n;i++){
			cin>>str;
			add(str);
		}
		cout<<s.size()<<endl;
	}
	return 0;
}