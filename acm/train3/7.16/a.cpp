#include <bits/stdc++.h>
using namespace std;
int n;
double a[10010],avr,sum=0;
int main(){
	int i;
	while(1){
		cin>>n;
		if(n==0)break;
		sum=0;
		for(i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		avr=sum/(double)n;
		sum=0;
		for(i=0;i<n;i++){
			if(a[i]<=avr)sum=sum+1;
		}
		cout<<sum<<endl;
	}
	return 0;
}