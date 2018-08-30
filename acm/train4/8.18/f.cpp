#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
	cin>>n>>s;
	int i,j,k;
	for(i=1;i<n;i++)if(s[i]!=s[i-1])break;
	if(i==n){
		cout<<-1<<endl;
		return 0;
	}
}