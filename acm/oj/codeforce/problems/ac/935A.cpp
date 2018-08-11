#include <bits/stdc++.h>
using namespace std;
inline double discount(double a,double b){
	if(a>=20&&a<24)return 0;
	return (20-1-a)*60+60-b;
}
double hh,mm,h,d,c,n;
double ans1,ans2;
int main(){
	cin>>hh>>mm>>h>>d>>c>>n;
	ans1=ceil(h/n)*c;
	ans2=ceil((d*discount(hh,mm)+h)/n)*c*0.8;
	cout<<min(ans1,ans2);
	return 0;
}