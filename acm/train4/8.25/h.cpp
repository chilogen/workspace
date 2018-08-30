#include <bits/stdc++.h>
using namespace std;
const int maxn=1e7;

map<pair<int,int>,int>ma;

vector<pair<int,int> >v;

int query(int x,int y){
	pair<int,int>tp=make_pair(x,y);
	if(ma.count(tp)!=0)return ma[tp];
	printf("? %d %d\n",x,y);

	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	ma[tp]=ans;
	return ans;
}

int solve(int x1,int y1,int x2,int y2){
	if(x2<x1||y2<y1)return 0;
	int ans,tans;
	ans=query(x2,y2);
	if(ans==0)return 0;
	if(x1==x2&&y1==y2){
		int i,j,k;
		i=query(x1-1,y1-1);
		j=query(x1-1,y1);
		k=query(x1,y1-1);
		if(ans-j-k+i==1){
			v.push_back(make_pair(x1,y1));
			return 1;
		}
		return 0;
	}

	int lx=x1,ly=y1,rx=x2,ry=y2,l,mx,my,cnt=0;
	while(lx<rx){
		mx=(lx+rx)>>1;
		my=(ly+ry)>>1;
		tans=query(mx,my);
		if(tans<ans){
			if(mx==rx-1){
				l=(rx-x1)>>1;
				cnt+=solve(x1,y1,x1+l,y1+l);
				if(cnt<ans)cnt+=solve(x1+l+1,y1+l+1,rx,ry);
				if(cnt<ans)cnt+=solve(x1,y1+l+1,x1+l,ry);
				if(cnt<ans)cnt+=solve(x1+l+1,y1,rx,y1+l);
				return cnt;
			}
			else{
				lx=mx;
				ly=my;
				continue;
			}
		}
		if(tans==ans){
			if(mx!=rx){
				rx=mx;
				ry=my;
				continue;
			}
			else{

			}
		}
	}
	v.push_back(make_pair(mx,my));
	return cnt+1;
}

int main(){
	int i;cin>>i;
	solve(-maxn,-maxn,maxn,maxn);
	printf("!");
	for(i=0;i<(int)v.size();i++)printf(" %d %d",v[i].first,v[i].second);
	printf("\n");
	fflush(stdout);
	return 0;
}