#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k;
	string s;
	cin>>j;	k=j;
	cin>>s;
	for(i=0;i<k-1;i++){
		if((s[i]=='U'&&s[i+1]=='R')||(s[i]=='R'&&s[i+1]=='U')){
			i++;j--;
		}
	}
	cout<<j<<endl;
	return 0;
}