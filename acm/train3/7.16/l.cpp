#include <bits/stdc++.h>
using namespace std;
int n,m,a[1010];
int main(){
	int i,j,k;
	while(1){
		k=-1;
		cin>>n>>m;
		if(n+m==0)break;
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		for(i=0;i<n;i++)for(j=i+1;j<n;j++){
			if(a[i]+a[j]>k&&a[i]+a[j]<=m)k=a[i]+a[j];
		}
		if(k==-1)cout<<"NONE\n";
		else cout<<k<<endl;
	}
	return 0;
}