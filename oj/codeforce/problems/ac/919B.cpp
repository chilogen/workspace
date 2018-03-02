#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool per(LL a){
	LL sum=0;
	while(a){
		sum=sum+a%10;
		if(sum>10)	return false;
		a=a/10;
	}
	if(sum==10)	return true;
	else return false;
}
int main(){
	LL i,j,k,n,ans;
	cin>>n;
	for(i=10;i<20000000;i++){
		if(per(i))	n--;
		if(n==0){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}