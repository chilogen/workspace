#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,t,x,y,t1,t2,x1,x2,y1,y2,dst;
	bool can=true;
	t1=x1=y1=0;
	cin>>n;
	while(n--){
		cin>>t2>>x2>>y2;
		t=t2-t1;	x=x2-x1;	y=y2-y1;
		dst=abs(x)+abs(y);
		if(dst==0)	dst=2;
		if(t%dst!=0)	can=false;
		t1=t2;	x1=x2;	y1=y2;
	}
	if(can)	cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}