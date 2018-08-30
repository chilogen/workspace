#include <bits/stdc++.h>
using namespace std;
int t;
struct point{
	double x,y;
};

typedef point Vector;

point operator-(point a,point b){return (point){a.x-b.x,a.y-b.y};}
double dot(point a,point b){return a.x*b.x+a.y*b.y;}
double length(point a,point b){return hypot(a.x-b.x,a.y-b.y);}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
Vector rotate(Vector v,double deg){
	double x,y;
	x=v.x*cos(deg)-v.y*sin(deg);
	y=v.x*sin(deg)+v.y*cos(deg);
	return (Vector){x,y};
}
point inter(point p,Vector v,point q,Vector w){
	Vector u=p-q;
	double t=cross(w,u)/cross(v,w);
	return (point){p.x+t*v.x,p.y+t*v.y};
}
point solve(point a,point b,point c){
	Vector v1=c-b,v2=a-b,v3,v4;
	double alpha=acos(dot(v1,v2)/length(b,c)/length(b,a));
	v3=rotate(v1,alpha/3);
	v1=b-c;v2=a-c;
	double belta=acos(dot(v1,v2)/length(b,c)/length(a,c));
	v4=rotate(v1,-belta/3);
	return inter(b,v3,c,v4);
}
point Read(){
	double x,y;
	cin>>x>>y;
	return (point){x,y};
}
void print(point a){cout<<setprecision(6)<<fixed<<a.x<<" "<<a.y<<" ";}
int main(){
	cin>>t;
	point a,b,c,d;
	while(t--){
		a=Read();b=Read();c=Read();
		d=solve(a,b,c);print(d);
		d=solve(b,c,a);print(d);
		d=solve(c,a,b);print(d);
		cout<<endl;
	}
	return 0;
}