#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=3e5;
LL sum=0,a[maxn];
int main(){
	LL n,m,b,i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0,j=0;i<m;i++){
		cin>>b;
		while(b-sum>a[j]){
			sum+=a[j];
			j++;
			if(j==n)break;
		}
		if(j==n)break;
		cout<<j+1<<" "<<b-sum<<endl;
	}
	return 0;
}