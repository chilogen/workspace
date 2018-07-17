#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,x,t,a[1010];
int main(){
	LL round,i,j;
	cin>>t;
	while(t--){
		cin>>x>>n;
		if(x<=n){
			for(i=0;i<x;i++)cout<<"1 ";
			for(;i<n;i++)cout<<"0 ";
			cout<<endl;
			continue;
		}
		if(n==1){
			cout<<x<<endl;
			continue;
		}
		round=(x-n)/(n-1);
		j=x-((n-1)*round+n);
		for(i=1;i<n-1;i++)a[i]=round+1;
		a[0]=a[n-1]=round/2+1;
		if(round%2==0){
			i=n-2;
			while(j--)a[i--]++;
		}
		else{
			a[0]++;
			i=1;
			while(j--)a[i++]++;
		}
		for(i=0;i<n;i++)cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}