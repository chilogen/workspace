#include <bits/stdc++.h>
using namespace std;
const double inf=1e15,eps=1e-7;
struct square{
	double x[5],y[5],k[4],b[4];
	void calc(){
		int i,j;
		double tx1,ty1,tx2,ty2;
		for(i=0;i<4;i++){
			j=(i+1)%4;
			tx1=x[i];tx2=x[j];
			ty1=y[i];ty2=y[j];
			if(tx1==tx2){
				k[i]=inf;
				continue;
			}
			if(ty1==ty2){
				k[i]=0;
				b[i]=0;
				continue;
			}
			k[i]=(ty1-ty2)/(tx1-tx2);
			b[i]=ty1-k[i]*tx1;
		}
		x[4]=(x[0]+x[2])/2;
		y[4]=(y[0]+y[2])/2;
	}
}s[2];
bool inter(square o,square p){
	int i,j,l,r,m;
	bool flag;
	double tmp;
	for(i=0;i<5;i++){
		double &x=o.x[i],&y=o.y[i];
		flag=true;
		for(j=0;j<2&&flag;j++){
			m=(j+2)%4;
			if(p.k[j]==inf){
				l=min(p.x[0],p.x[2]);
				r=max(p.x[0],p.x[2]);
				if(x<l||x>r) flag=false;
			}
			else if(p.k[j]==0){
				l=min(p.y[0],p.y[2]);
				r=max(p.y[0],p.y[2]);
				if(y<l||y>r) flag=false;				
			}
			else{
				tmp=(y-p.k[j]*x-p.b[j])*(y-p.k[m]*x-p.b[m]);
				if(tmp>eps)flag=false;
			}
		}
		if(flag)return true;
	}
	return false;
}
int main(){
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<4;j++){
			cin>>s[i].x[j]>>s[i].y[j];
		}
	}
	s[0].calc();s[1].calc();
	if(inter(s[0],s[1])||inter(s[1],s[0]))cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}