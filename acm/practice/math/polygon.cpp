#include <btis/stdc++.h>
using namespace std;
double area(vector<double>x,vector<double>y){
	double ans=0;
	int i;
	for(i=0;i<x.size()-1;i++){
		ans+=(x[i]*y[i+1]-x[i+1]*y[i]);
	}
	return fabs(ans/2);
}