#include <bits/stdc++.h>
using namespace std;
string s[2];
int main(){
	cin>>s[0]>>s[1];
	int i,j,k,l=s[0].length(),ans=0;
	if(l<2){
		cout<<0<<endl;
		return 0;
	}
	for(i=0;i<l-1;i++){
		for(j=i,k=0;j<=i+1;j++){
			if(s[0][j]=='X')k++;
			if(s[1][j]=='X')k++;
		}
		if(k>=2)continue;
		if(k==0){
			s[0][i]=s[1][i]=s[0][i+1]='X';
			ans++;
			continue;
		}
		s[0][i]=s[1][i]=s[0][i+1]=s[1][i+1]='X';
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}