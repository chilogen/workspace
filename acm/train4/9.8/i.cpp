#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[1000];
int main(){
	a[0]=0;a[1]=2;
	int j=0;
	int i;
	for(i=2;i<=20;i++){
		a[i]=(3*a[i-1]-a[i-2])/2+i+1;
		j+=a[i];
	}
	cout<<j+2<<endl;
	for(i=0;i<20;i++)cout<<a[i]<<" ";
}