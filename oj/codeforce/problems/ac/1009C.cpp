#include <bits/stdc++.h>
using namespace std;
double sum=0,x[100010],d[100010],sd;
int n,m;
inline double fun(double x){
	if(x==0)return 0;
	return (1+x)*x/2;
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=0;i<m;i++)cin>>x[i]>>d[i];
	for(i=0;i<m;i++){
		if(d[i]<0)j=n/2+n%2;
		else j=1;
		sd=fun(j-1)+fun(n-j);
		sum+=(n*x[i]+d[i]*sd);
	}
	printf("%.10lf\n",sum/n);
	return 0;
}