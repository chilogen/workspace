#include <bits/stdc++.h>
using namespace std;
const double eps=1e-5,pi=acos(-1);
double x[4],y[4],deg[4];
void solve(){
	int i,j;
	double a,b,c,d,e,f;
	a=x[1]*x[1]+y[1]*y[1]-x[0]*x[0]-y[0]*y[0];
	b=2*x[1]-2*x[0];
	c=2*y[1]-2*y[0];
	d=x[1]*x[1]+y[1]*y[1]-x[2]*x[2]-y[2]*y[2];
	e=2*x[1]-2*x[2];
	f=2*y[1]-2*y[2];
	y[3]=(b*d-e*a)/(b*f-e*c);
	x[3]=(a-c*y[3])/b;

	for(i=0;i<3;i++){
		j=(i+1)%3;
		a=hypot(x[i]-x[j],y[i]-y[j]);
		b=hypot(x[i]-x[3],y[i]-y[3]);
		c=hypot(x[j]-x[3],y[j]-y[3]);
		deg[i]=acos((b*b+c*c-a*a)/(2*b*c));
	}
	for(i=3;i<100;i++){
		deg[3]=360.0/(double)i;
		for(j=0;j<3;j++){
			a=180.0*deg[j]/pi;
			b=fmod(a,deg[3]);
			c=fabs(b-deg[3]);
			if(fabs(b)>eps&&fabs(b-deg[3])>eps)break;
		}
		if(j==3){
			cout<<i<<endl;
			return;
		}
	}
}
int main(){
	int i;
	for(i=0;i<3;i++)cin>>x[i]>>y[i];
	solve();
	return 0;
}