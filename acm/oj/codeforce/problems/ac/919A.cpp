#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,i,j;
	double m,a,b,per=1000000000,t;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a>>b;
		if(a/b<per)	per=a/b;
	}
	printf("%.8lf\n",per*m);
	return 0;
}