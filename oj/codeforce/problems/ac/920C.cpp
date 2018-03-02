#include <bits/stdc++.h>
using namespace std;
int a[200010];
int n;
int main(){
	string s;
	int i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>s;
	int len=s.length();
	s.push_back('0');
	bool start=false;
	int st,en;
	for(i=0;i<n;i++){
		if(s[i]=='1'){
			if(start==false){
				start=true;
				st=i;
			}
		}
		if(s[i]=='0'){
			if(start==true){
				start=false;
				en=i;
				sort(a+st,a+en+1);
			}
		}
	}
	for(i=0;i<n;i++){
		if(a[i]!=i+1){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}