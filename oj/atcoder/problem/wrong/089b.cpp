#include <bits/stdc++.h>
using namespace std;
int n,k,c[2010][2010]={0};
inline int lowbit(int x){return x&-x;}
void add(int x,int y,int v){
	int i,j;
	x++;y++;
	for(i=x;i<=2*k+1;i+=lowbit(i))
		for(j=y;j<=2*k+1;j+=lowbit(j))	c[i][j]+=v;
}
int get(int x,int y){
	int i,j,sum=0;
	x++;y++; 
	for(i=x;i>0;i-=lowbit(i))
		for(j=y;j>0;j-=lowbit(j))	sum+=c[i][j];
	return sum;
}
inline int sum(int x1,int y1,int x2,int y2){
	if(x2<x1||y2<y1||x1<0||y1<0)	return 0;
	if(x2>2*k-1)	x2=2*k-1;
	if(y2>2*k-1)	y2=2*k-1;
	if(x1>2*k-1)	x1=2*k-1;
	if(y1>2*k-1)	y1=2*k-1;
	return get(x2,y2)-get(x1-1,y2)-get(x2,y1-1)+get(x1-1,y1-1);
}
int main(){
	int i,j,x,y,ans=0,now;
	char c;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>x>>y>>c;
		if(c=='W')	y+=k;
		add(x%(2*k),y%(2*k),1);
	}
	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
			now=sum(i,j,i+k-1,j+k-1)+sum(i+k,j+k,2*k-1,2*k-1)+sum(i+k,0,2*k-1,j-1)+sum(0,0,i-1,j-1)+sum(0,j+k,i-1,2*k-1);
			if(now>ans)	ans=now;
		}
	}
	cout<<ans<<endl;
	return 0;
}