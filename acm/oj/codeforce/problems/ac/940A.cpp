#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL sum[110],n,d,i,j,k,ans=10000;
	cin>>n>>d;
	memset(sum,0,sizeof(sum));
	for(i=0;i<n;i++){
		cin>>j;
		sum[j]++;
	}
	for(i=1;i<=100;i++){
		k=0;
		for(j=0;j<=d;j++){
			if(i+j<=100)
			k+=sum[i+j];
		}
		k=n-k;
		if(k<ans)ans=k;
	}
	cout<<ans<<endl;
	return 0;
}