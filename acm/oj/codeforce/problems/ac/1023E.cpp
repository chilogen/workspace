#include <bits/stdc++.h>
using namespace std;
bool query(int r1,int c1,int r2,int c2){
	cout<<"? "<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
	string s;
	cin>>s;
	if(s=="YES")return true;
	return false;
}
string ans1="",ans2="";
int main(){
	int x,y,n;
	cin>>n;
	x=y=1;
	while(x+y<=n){
		if(x+1<=n&&query(x+1,y,n,n)){
			ans1+="D";
			x++;
		}
		else{
			ans1+="R";
			y++;
		}
	}
	x=y=n;
	while(x+y>n+1){
		if(y-1>=1&&query(1,1,x,y-1)){
			ans2+="R";
			y--;
		}
		else{
			ans2+="D";
			x--;
		}
	}
	reverse(ans2.begin(),ans2.end());
	cout<<"! "<<ans1+ans2<<endl;
	return 0;
}