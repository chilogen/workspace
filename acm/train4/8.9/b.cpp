#include <bits/stdc++.h>
using namespace std;
typedef int LL;
vector<pair<LL,LL>>v[51];
int main(){
	LL c=-1,x,y,z,i,j,k;
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	while(c!=3){
		cin>>c;
		if(c==0)	for(i=0;i<51;i++)v[i].clear();
		else{
			cin>>x>>y>>z;
			if(c==1)v[z].push_back(make_pair(x,y));
			else if(c==2){
				for(i=0,k=0;i<=50;i++)for(j=0;j<(LL)v[i].size();j++)
					if(v[i][j].first>=1&&v[i][j].first<=x&& \
					   v[i][j].second>=y&&v[i][j].second<=z){
						k++;
						break;
					}
				cout<<k<<endl;
			}
		}
	}
	return 0;
}