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

/**************************/

const Double Inf=1e20;
const Int maxn=5e4+10;
Point p[maxn],s,t;
Double len;
Int T,n,q;

void print(Double x,Point A){
	cout<<setprecision(7)<<fixed;
	cout<<x<<" "<<A.x<<" "<<A.y<<endl;
}

void solve(){
	len=Inf;
	Int i,j;
	Point tp,ans,q,w;
	Double l;
	for(i=0,j=1;i<n;i++,j++){
		if(OnSegment(s,p[i],p[j])){
			print(Length(s-t),s);
			return;
		}
		if(OnSegment(t,p[i],p[j])){
			print(Length(s-t),t);
			return;
		}
		tp=SymmetryPoint(s,p[i],p[j]);
		l=Length(tp-t);
		if(l<len){
			len=l;
			ans=tp;
			q=p[i];
			w=p[j]-p[i];
		}
	}
	tp=LineIntersecion(q,w,ans,ans-t);
	print(len,tp);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("flags.in","r",stdin);	
	Int i,Kase=1;
	cin>>T;
	while(T--){
		cout<<"Case "<<Kase++<<":\n";
	
		cin>>n;
		for(i=0;i<n;i++)cin>>p[i].x>>p[i].y;
		p[n]=p[0];

		cin>>q;
		for(i=0;i<q;i++){
			cin>>s.x>>s.y>>t.x>>t.y;
			solve();
		}
	}
	return 0;
}