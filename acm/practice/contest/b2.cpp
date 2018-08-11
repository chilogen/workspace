#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[100010],b[10010];
bool check(LL x,LL c){
	LL j,cnt=0;
	memcpy(b,a,sizeof(b));
	for(j=x;j>0&&cnt<=3;j--){
		if(b[j]-b[j-1]!=c){
			cnt++;
			b[j-1]=b[j]-c;
		}
	}
	for(j=x+1;j<n&&cnt<=3;j++){
		if(b[j]-b[j-1]!=c){
			cnt++;
			b[j]=b[j-1]+c;
		}
	}
	return cnt<=3;
}
int main(){
	LL i,j,k,l;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<min(n,(LL)4);i++){
		for(j=i+1;j<n;j++){
			k=a[j]-a[i];
			l=j-i;
			if(k%l!=0)continue;
			k/=l;
			if(!check(i,k))continue;
			for(k=0;k<n;k++)cout<<b[k]<<" ";
			return 0;
		}
	}
	return 0;
}