#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long Int;
typedef long double Double;

const Double eps=1e-9,pi=acos(-1);

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
Vec
tor operator -(Vector v1,Vector v2){return (Vector){v1.x-v2.x,v1.y-v2.y};}
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

bool vis[210][210];
int ans;
Point v[510];
const int base=102;
int n;

inline bool havepoint(Point a,Point b,Point c,Double deg){
	int x[2],y[2],i,j;
	Double d;
	Vector v1=a-b;
	x[0]=floor(c.x);x[1]=floor(c.x+1);
	y[0]=floor(c.y);y[1]=floor(c.y+1);
	for(i=0;i<2;i++)for(j=0;j<2;j++){
		if(x[i]<-100||x[i]>100)continue;
		if(y[i]<-100||y[i]>100)continue;
		if(!vis[ x[i]+base ][ y[j]+base ])continue;
		c=(Point){(Double)x[i],(Double)y[j]};
		Vector v2=c-b;
		d=Angle(v2,v1);
		if(dcmp(deg,d)==0){
			return true;
		}
	}
	return false;
}

bool dfs(Point a,Point b,int p,Double deg){
	if(p==2)return true;
	Vector v1=b-a,v2;
	Point c;
	v2=Rotate(v1,deg);
	c=b+v2;
	if(!havepoint(a,b,c,deg))return false;
	return dfs(b,c,p-1,deg);
}

void check(int i,int j,int p){
	Double deg=pi/2.0;
	bool f;
	f=dfs(v[i],v[j],p,deg);
	if(f)ans+=4;
	f=dfs(v[i],v[j],p,-deg);
	if(f)ans+=4;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int i,j,x,y;
	while(cin>>n){
		memset(vis,0,sizeof(vis));
		ans=0;
		for(i=0;i<n;i++){
			cin>>x>>y;
			vis[x+base][y+base]=1;
			v[i]=(Point){(Double)x,(Double)y};
		}
		for(i=0;i<n;i++)for(j=i+1;j<n;j++)
			check(i,j,4);
		cout<<ans/16<<endl;
	}
	return 0;
}