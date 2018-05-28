#include <bits/stdc++.h>
using namespace std;
double cost,gross;
double a,b,c,d,A,B,C,D;
int Case=0,n;
int main(){
	cin>>n;
	int i;
	while(n!=0){
		Case++;
		A=B=C=D=0;
		for(i=0;i<n;i++){
			cin>>a>>b>>c>>d;
			A+=a;B+=b;C+=c;D+=d;
		}
		gross=A*0.8+B+C*1.2+D*0.8;
		a=A/85.0*7.5;
		b=B/85.0*24;
		c=C/85*32;
		d=D*0.2;
		cost=a+b+c+d+(A+B+C)/85.0*8;
		printf("Case #%d: RM%.2lf\n",Case,gross-cost);
		cin>>n;
	}
	return 0;
}