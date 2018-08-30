#include <bits/stdc++.h>
using namespace std;
bool vis[210][210];
const int base=102;
pair<int,int>v[510];
int n,ans;
int main(){
	int i,j,x1,y1,x2,y2,k;
	while(cin>>n){
		ans=0;
		memset(vis,0,sizeof(vis));
		for(i=0;i<n;i++){
			cin>>v[i].first>>v[i].second;
			vis[v[i].first+base][v[i].second+base]=1;
		}
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(v[i].first==v[j].first){
					k=fabs(v[j].second-v[i].second);
					x1=v[i].first-k+base;
					if(x1>0)
						if(vis[x1][v[i].second+base]&&vis[x1][v[j].second+base])ans+=4;
					x1=v[i].first+k+base;
					if(x1<210)
						if(vis[x1][v[i].second+base]&&vis[x1][v[j].second+base])ans+=4;
					if(k%2==1)continue;
					x1=v[i].first-k/2+base;
					x2=v[i].first+k/2+base;
					y1=(v[i].second+v[j].second)/2+base;
					if(x1>0&&x2<210)
						if(vis[x1][y1]&&vis[x2][y1])ans+=4;
				}
				if(v[i].second==v[j].second){
					k=fabs(v[j].first-v[i].first);
					y1=v[i].second-k+base;
					if(y1>0)
						if(vis[v[i].first+base][y1]&&vis[v[j].first+base][y1])ans+=4;
					y1=v[i].second+k+base;
					if(y1<210)
						if(vis[v[i].first+base][y1]&&vis[v[j].first+base][y1])ans+=4;
					if(k%2==1)continue;
					x1=(v[i].first+v[j].first)/2+base;
					y1=v[i].second+k/2+base;
					y2=v[i].second-k/2+base;
					if(y1>0&&y2<210)
						if(vis[x1][y1]&&vis[x1][y2])ans+=4;
				}
			}
		}
		cout<<ans/12<<endl;
	}
	return 0;
}