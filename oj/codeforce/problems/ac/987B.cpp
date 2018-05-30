#include <bits/stdc++.h>
using namespace std;
double x,y,a,b,tmp;
int main(){
	cin>>x>>y;
	if(x==y){
		cout<<"=\n";
		return 0;
	}
	double a=y*log(x);
	double b=x*log(y);
	if(a>b)cout<<">\n";
	else if(a==b)cout<<"=\n";
	else cout<<"<\n";
	return 0;
}