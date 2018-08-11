#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dst[100010]={0};
LL fat[100010];
LL n,m,l,r,d;
int getfat(int x){
	if(x==fat[x])return x;
	LL i=getfat(fat[x]);
	dst[x]+=dst[fat[x]];
	return i;
}
int main(){
	LL i,j,k;
	for(i=0;i<100010;i++)fat[i]=i;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>l>>r>>d;
		j=getfat(l);
		k=getfat(r);
		if(j==k&&d!=dst[l]-dst[r]){
			cout<<"No"<<endl;
			return 0;
		}
		if(j==k&&d==dst[l]-dst[r])	continue;
		if(j!=k){
			if(d>dst[l]){
				fat[j]=k;
				dst[j]=dst[r]+d-dst[l];
			}
			else if(d+dst[r]>dst[l]){
				fat[j]=k;
				dst[j]=dst[r]+d-dst[l];
			}
			else if(d+dst[r]<dst[l]){
				fat[k]=j;
				dst[k]=dst[l]-d-dst[r];
			}
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}