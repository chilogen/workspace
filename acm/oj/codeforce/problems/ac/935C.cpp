#include <bits/stdc++.h>
using namespace std;
double x1,x2,yy1,y2,R,r;
double ab=1e-7;
inline double dist(double x,double y){
	return sqrt(x*x+y*y);
}
int main(){
	cin>>R>>x1>>yy1>>x2>>y2;
	double d=dist(x2-x1,y2-yy1);
	if((d>R)&&abs(d-R)>ab){
		cout<<x1<<" "<<yy1<<" "<<R<<endl;
		return 0;
	}
	d=d+R;
	r=d/2;
	double k,b,px,py,the;
	if(abs(x1-x2)<ab){
		px=x1;
		if(y2>yy1)py=y2-r;
		else py=y2+r;
		printf("%.8lf %.8lf %.8lf\n",px,py,r);
	}
	else{
		the=atan((y2-yy1)/(x2-x1));
		if(the>0&&x2<x1)the=the+3.1415926;
		else if(the<0&&x2<x1)the=the+3.1415926;
		px=x2-cos(the)*r;
		py=y2-sin(the)*r;
		printf("%.8lf %.8lf %.8lf\n",px,py,r);
	}
	return 0;
}