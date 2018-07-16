#include <bits/stdc++.h>
using namespace std;
int ma[11][11]={0},ans,d,w;
int x11,y11,x22,y22;
void check(){
	int i,j,k,l=0,m=10,n=0;
	for(i=y11;i<=y22;i++)m=min(m,min(ma[i][x11],ma[i][x22]));
	for(i=x11;i<=x22;i++)m=min(m,min(ma[y11][i],ma[y22][i]));
	for(i=y11+1;i<y22;i++)
		for(j=x11+1;j<x22;j++){
			l+=ma[i][j];
			n=max(n,ma[i][j]);
		}
	if(n>=m)return;
	k=(x22-x11-1)*(y22-y11-1)*m;
	ans=max(ans,k-l);
}
int main(){
	int i,j;
	while(1){
		cin>>d>>w;
		if(d+w==0)break;
		ans=0;
		for(i=0;i<d;i++)for(j=0;j<w;j++)cin>>ma[i][j];
		for(x11=0;x11<w;x11++)for(y11=0;y11<d;y11++)
		for(x22=x11+2;x22<w;x22++)for(y22=y11+2;y22<d;y22++)check();
		cout<<ans<<endl;
	}
	return 0;
}