#include <bits/stdc++.h>
using namespace std;
int main(){
	long double a,b;
	long long l,r;
	cin>>a>>b;
	a+=1e-15;
	b+=1e-15;
	l=a*1000000000;
	r=b*1000000000;
	a=l%r;
	a=a/1000000000.0;
	printf("%.15lf\n",(double)a);
	return 0;
}