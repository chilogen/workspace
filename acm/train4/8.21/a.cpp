#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10;


struct point{
	LL x,y,v;
}p[maxn];

struct DP{
	point a;
	LL v;
}dp[2][maxn];

bool cmp(point a,point b){
	if(a.y==b.y)return a.x<b.x;
	return a.y<b.y;
}

bool low(point a,point b){
	return ((a.x<b.x)&&(a.y<b.y));
}

void solve(){
	LL n,i,j;
	cin>>n;
	for(i=1;i<=n;i++)cin>>p[i].x>>p[i].y>>p[i].v;
	sort(p+1,p+1+n,cmp);p[0]=p[1];
	
	DP fir=(DP){(point){1000000002,1000000002},-1};
	for(i=0;i<2;i++)for(j=0;j<maxn;j++)dp[i][j]=fir;
	dp[0][0]=dp[1][0]=(DP){(point){-1,-1},0};;
	LL cur=0,pre=1,p1=0,p2,sz=1,ans=0,mv=0;
	
	for(i=1;i<=n;i++){
		if(p[i].y!=p[i-1].y){
			for(j=p1+1;;j++){
				if(dp[pre][j].v==-1)break;
				if(dp[pre][j].v<=mv)continue;
				mv=dp[pre][j].v;
				dp[cur][sz++]=dp[pre][j];
			}
			swap(cur,pre);
			p1=0;sz=1;mv=0;
		}
		for(p2=p1+1;p2<maxn;p2++){
			if(!low(dp[pre][p2].a,p[i]))break;
			if(dp[pre][p2].v>dp[pre][p1].v)p1=p2;
		}
		dp[cur][sz]=(DP){p[i],p[i].v+dp[pre][p1].v};
		mv=max(mv,dp[cur][sz].v);
		ans=max(dp[cur][sz].v,ans);
		sz++;
	}
	cout<<ans<<endl;
}

int main(){
	int t;
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}