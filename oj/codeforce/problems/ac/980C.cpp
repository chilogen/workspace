#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10;
LL fix[maxn],a[maxn],lef[maxn];
LL n,k;
int main(){
	memset(fix,-1,sizeof(fix));
	memset(lef,0,sizeof(lef));
	cin>>n>>k;
	LL i,j,l;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(fix[a[i]]==-1){
			l=maxn;
			lef[a[i]]=maxn;
			for(j=a[i];a[i]-j<k&&j>=0;j--){
				if(fix[j]!=-1){
					if(a[i]-j<=lef[j]){
						l=fix[j];
						lef[a[i]]=lef[j]-(a[i]-j);
					}
					else l=j+1;
					break;
				}
			}
			lef[a[i]]=min(k-(a[i]-j),lef[a[i]]);
			for(j=j+1,l=min(j,l);j<=a[i];j++){
				fix[j]=l;
			}
		}
	}
	for(i=0;i<n;i++){
		cout<<fix[a[i]]<<" ";
	}
	return 0;
}