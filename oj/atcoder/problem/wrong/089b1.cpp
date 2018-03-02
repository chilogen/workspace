#include <bits/stdc++.h>
using namespace std;
int c[2010][2010]={0},num[2010][2010]={0},n,k;
inline int sum(int x1,int y1,int x2,int y2){
	if(x2<x1||y2<y1||x1<1||y1<1)	return 0;
	if(x2>2*k)	x2=2*k;
	if(y2>2*k)	y2=2*k;
	if(x1>2*k)	x1=2*k;
	if(y1>2*k)	y1=2*k;
	return num[x2][y2]-num[x1-1][y2]-num[x2][y1-1]+num[x1-1][y1-1];
}
int main(){
	int i,j,l,x,y,ans=0,now;
	char a;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>x>>y>>a;
		if(a=='W')	y+=k;
		c[x%(2*k)+1][y%(2*k)+1]++;
	}
	for(i=1;i<2010;i++){
		for(j=1;j<2010;j++){
			num[i][j]=num[i-1][j]+num[i][j-1]-num[i-1][j-1]+c[i][j];
		}
	}
	for(i=1;i<=2*k;i++){
		for(j=1;j<=2*k;j++){
			now=sum(i,j,i+k-1,j+k-1)+sum(i+k,j+k,2*k,2*k)+ \
			sum(i+k,1,2*k,j-1)+sum(1,1,i-1,j-1)+sum(1,j+k,i-1,2*k);
			if(now>ans)	ans=now;
		}
	}
	cout<<ans<<endl;
	return 0;
}