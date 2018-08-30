#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
typedef long double Double;

const Double eps=1e-9;

struct Point{
	Double x,y;
};

typedef Point Vector;

Int dcmp(Double x,Double y){
	if(fabs(fabs(x)-fabs(y))<eps)return 0;
	if(x>y)return 1;
	return -1;
}

Vector operator +(Vector v1,Vector v2){return (Vector){v1.x+v2.x,v1.y+v2.y};}
Vector operator -(Vector v1,Vector v2){return (Vector){v1.x-v2.x,v1.y-v2.y};}
Vector operator *(Vector v1,Double p){return (Vector){v1.x*p,v1.y*p};}
Vector operator /(Vector v1,Double p){return (Vector){v1.x/p,v1.y/p};}
bool operator ==(Vector &v1,Vector &v2){return dcmp(v1.x,v2.x)==0&&dcmp(v1.y,v2.y)==0;}

Double Dot(Vector v1,Vector v2){return v1.x*v2.x+v1.y*v2.y;}
Double Length(Vector v1){return sqrt(Dot(v1,v1));}
Double Angle(Vector v1,Vector v2){return acos(Dot(v1,v2)/Length(v1)/Length(v2));}
Double Cross(Vector v1,Vector v2){return v1.x*v2.y-v1.y*v2.x;}

//anti-clockwise rotate
Vector Rotate(Vector v1,Double deg){
	Double x,y;
	x=v1.x*cos(deg)-v1.y*sin(deg);
	y=v1.x*sin(deg)+v1.y*cos(deg);
	return (Vector){x,y};
}

Point LineIntersecion(Point p,Vector v,Point q,Vector w){
	Vector u=p-q;
	Double t=Cross(w,u)/Cross(v,w);
	return p+v*t;
}

Double Dist2Line(Point P,Point A,Point B){
	Vector v1=B-A,v2=P-A;
	//return Cross(v1,v2)/Length(v1);
	return fabs(Cross(v1,v2)/Length(v1));
}

Double Dist2Segment(Point P,Point A,Point B){
	if(A==B)return Length(P-A);
	Vector v1=B-A,v2=P-A,v3=P-B;
	if(dcmp(Dot(v1,v2),0)<0)return Length(v1);
	if(dcmp(Dot(v1,v3),0)>0)return Length(v3);
	return Dist2Line(P,A,B);
}

Point LineProjection(Point P,Point A,Point B){
	Vector v=B-A;
	Double t0=Dot(v,P-A)/Dot(v,v);
	return A+v*t0;
}

Point SymmetryPoint(Point P,Point A,Point B){
	Point Q=LineProjection(P,A,B);
	Vector v=Q-P;
	return P+v*2;
}

bool OnLine(Point P,Point A,Point B){
	if(P==A||P==B)return true;
	Vector v1=P-A,v2=B-A;
	if(dcmp(Cross(v1,v2),0)==0)return true;
	return false;
}

bool OnSegment(Point P,Point A,Point B){
	if(!OnLine(P,A,B))return false;
	Double x1,x2,y1,y2;
	x1=min(A.x,B.x);x2=max(A.x,B.x);
	y1=min(A.y,B.y);y2=max(A.y,B.y);
	if(P.x>=x1&&P.x<=x2&&P.y>=y1&&P.y<=y2)return true;
	//if(P.x>x1&&p.x<x2&&p.y>y1&&P.y<y2)return true;
	return false;
}
