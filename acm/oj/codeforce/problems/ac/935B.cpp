#include <bits/stdc++.h>
using namespace std;
int main(){
	int side,i,j,k,len,ans=0,x=0,y=0;;
	string s;
	cin>>len>>s;
	if(s[0]=='U'){
		y++;
		side=0;
	}
	else{
		x++;
		side=1;
	}
	for(i=1;i<len;i++){
		if(s[i]=='U'){
			y=y+1;
			if(x==y)continue;
			if(y-x>0) k=0;
			else k=1;
			if(k!=side){
				side=k;
				ans++;
			}
		}
		if(s[i]=='R'){
			x=x+1;
			if(x==y)continue;
			if(y-x>0) k=0;
			else k=1;
			if(k!=side){
				side=k;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}