#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool c[53][53]={0};
LL l[53][53];
LL len,sum,sumb=0,h,w;
char m;
queue<pair<LL,LL>>q;
int main(){
	LL i,j,k;
	LL x[]={1,-1,0,0},y[]={0,0,1,-1};
	cin>>h>>w;
	for(i=1;i<=h;i++){
		for(j=1;j<=w;j++){
			cin>>m;
			if(m=='.')c[i][j]=1;
			else sumb++;
		}
	}
	for(i=0;i<53;i++){
		for(j=0;j<53;j++)l[i][j]=(LL)1e9;
	}
	l[1][1]=0;
	q.push(make_pair(1,1));
	while(!q.empty()){
		pair<LL,LL>tp=q.front();
		q.pop();
		LL xx=tp.first,yy=tp.second;
		LL xx1,yy1;
		for(i=0;i<4;i++){
			xx1=xx+x[i];
			yy1=yy+y[i];
			if(xx1<1||xx1>h||yy1<1||yy1>w)continue;
			if(!c[xx1][yy1])continue;
			if(l[xx1][yy1]>l[xx][yy]+1){
				l[xx1][yy1]=l[xx][yy]+1;
				q.push(make_pair(xx1,yy1));
			}
		}
	}
	sum=h*w-l[h][w]-sumb-1;
	if(l[h][w]!=(LL)1e9)cout<<sum<<endl;
	else cout<<-1<<endl;
	return 0;
}