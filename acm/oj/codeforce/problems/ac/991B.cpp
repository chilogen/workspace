#include <bits/stdc++.h>
using namespace std;
double a[100],sum=0,n;

int main(){
	int i,k;
	cin>>n;
	k=n;
	for(i=0;i<k;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+k);i=0;
	while(sum/n<4.5){
		sum+=(5-a[i]);
		i++;
	}
	cout<<i<<endl;
	return 0;
}