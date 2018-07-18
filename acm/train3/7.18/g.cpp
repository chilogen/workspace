#include <iostream>
using namespace std;
typedef long long LL;
LL t;
double x[4],y[4],h[4],w[4],area,join,ans;
inline void sswap(){
	swap(x[0],x[1]);
	swap(y[0],y[1]);
	swap(h[0],h[1]);
	swap(w[0],w[1]);
}
int main(){
	cin>>t;
	while(t--){
		cin>>x[0]>>y[0]>>w[0]>>h[0];
		cin>>x[1]>>y[1]>>w[1]>>h[1];
		area=h[0]*w[0]+h[1]*w[1];
		x[2]=max(x[0],x[1]);
		x[3]=min(x[0]+w[0],x[1]+w[1]);
		y[2]=max(y[0],y[1]);
		y[3]=min(y[0]+h[0],y[1]+h[1]);
		if(y[3]<y[2]||x[3]<x[2])join=0;
		else join=(y[3]-y[2])*(x[3]-x[2]);
		printf("%.2lf\n",join/(area-join));
	}
	return 0;
}