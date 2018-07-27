#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
double a[1010],b[1010],fule=0;
bool solve(){
	int i,j=0;
	double w,x;
	for(i=1;i<=n;i++){
		w=m+fule;
		if(j%2==0){
			if(b[i]-1<=0)return false;
			x=w/(b[i]-1);
			fule+=x;
			j=(j+1)%2;
		}
		else{
			if(a[i]-1<=0)return false;
			x=w/(a[i]-1);
			fule+=x;
			j=(j+1)%2;
		}
	}
	for(i=n;i>=1;i--){
		w=m+fule;
		if(j%2==0){
			if(b[i]-1<=0)return false;
			x=w/(b[i]-1);
			fule+=x;
			j=(j+1)%2;
		}
		else{
			if(a[i]-1<=0)return false;
			x=w/(a[i]-1);
			fule+=x;
			j=(j+1)%2;
		}
	}
	return true;
}
int main(){
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	a[n+1]=a[0]=2;
	for(i=1;i<=n;i++)cin>>b[i];
	if(solve())printf("%.10lf\n",fule);
	else cout<<-1<<endl;
	return 0;
}