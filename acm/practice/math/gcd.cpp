#include <bits/stdc++.h>
using namespace std;
double eps=1e-3;//调整浮点数公约数精度
int gcd(int a,int b){
	int c=a+b,r;
	a=c-min(a,b);
	b=c-a;
	r=a%b;
	if(r==0)return b;
	else return gcd(a,r);
}
int gcd1(int a,int b){
	return b==0?a:gcd1(b,a%b);
}
double fgcd(double x,double y)
{
     double r=x-floor(x/y)*y;
     while(fabs(r)>0.1)
     {
         x=y;
         y=r;
         r=x-floor(x/y)*y;
     }
     return y;
}
double fgcd1(double x,double y){
	return fabs(y)<eps?x:fgcd1(y,x-floor(x/y)*y);
}
int main(){
	double i,j;
	while(1){
		cin>>i>>j;
		cout<<gcd1(i,j)<<endl;
	}
	return 0;
}
