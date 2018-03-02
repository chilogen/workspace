#include <bits/stdc++.h>
using namespace std;
int k,h,m,a,b,ans=0;
bool ok(int x,int y){
	int a,b,c,d;
	a=x%10;
	b=x/10;
	c=y%10;
	d=y/10;
	if(a==7||b==7||c==7||d==7)	return true;
	else return false;
}
int main(){
	cin>>k>>h>>m;
	a=h;b=m;
	while(!ok(a,b)){
		b=b-k;
		ans++;
		if(b<0){
			a-=1;
			if(a<0)	a=23;
			b+=60;
		}
	}
	cout<<ans<<endl;
	return 0;
}