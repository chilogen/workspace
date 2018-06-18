#include <bits/stdc++.h>
using namespace std;
int n,x,y;
int horizen=0,lef[14]={0},rig[14]={0};
inline int setone(int x,int i){x^=(1<<i);return x;}
inline bool checkone(int &x,int i){return (x&(1<<i))!=0;}
vector<int>tmpans;
vector<vector<int>>ans;
void dfs(int d,int l,int h,int r){
	int i,nl,nh,nr;
	if(d==n+1){
		ans.push_back(tmpans);
		return;
	}
	l|=lef[d];r|=rig[d];
	if(d==x){
		nl=l<<1;
		nh=h;
		nr=r>>1;
		tmpans.push_back(y);
		dfs(d+1,nl,h,nr);
		tmpans.pop_back();
	}
	else{
		for(i=1;i<=n;i++){
			if(checkone(l,i))continue;
			if(checkone(h,i))continue;
			if(checkone(r,i))continue;
			nl=setone(l,i)<<1;
			nh=setone(h,i);
			nr=setone(r,i)>>1;
			tmpans.push_back(i);
			dfs(d+1,nl,nh,nr);
			tmpans.pop_back();
		}
	}
}
int main(){
	cin>>n>>x>>y;
	int i,j,k;
	horizen=setone(horizen,y);
	for(i=x,j=y;j>=0&&i>=0;i--,j--)lef[i]=setone(lef[i],j);
	for(i=x+1,j=y+1;j<=n&&i<=n;i++,j++)lef[i]=setone(lef[i],j);
	for(i=x,j=y;j<=n&&i>=0;i--,j++)rig[i]=setone(rig[i],j);
	for(i=x+1,j=y-1;j>=0&&i<=n;i++,j--)rig[i]=setone(rig[i],j);
	dfs(1,lef[0]<<1,horizen,rig[i]>>1);
	k=ans.size();
	cout<<k<<endl;
	for(i=0;i<k;i++){
		for(j=0;j<n;j++)cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}