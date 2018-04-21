#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
class BuildingSpanningTreesDiv2{
public:
	LL mod=987654323;
	LL fat[1010],cnt[1010]={0},unvis=0;
	set<LL>s;
	vector<LL>v;
	int getNumberOfSpanningTrees(int n, vector <int> x, vector <int> y){
	 	LL i,j;
	 	for(i=0;i<1000;i++)fat[i]=i;
	 	for(i=0;i<(LL)x.size();i++){
	 		connect(x[i],y[i]);
	 		s.insert(x[i]);
	 		s.insert(y[i]);
	 	}
	 	for(i=1;i<=n;i++){
	 		if(s.count(i)==0)continue;
	 		cnt[getfat(i)]++;
	 	}
	 	for(i=1;i<=n;i++){
	 		if(cnt[i]!=0)v.push_back(cnt[i]);
	 		if(s.count(i)==0)unvis++;
	 	}
	 	if(unvis>2)return 0;
	 	if(unvis==0){
	 		j=0;
	 		for(i=0;i<3;i++){
	 			if(i==0){
	 				j=j+(((v[0]*v[1])%mod)*((v[0]*v[2])%mod))%mod;
	 				j=j%mod;
	 			}
	 			if(i==1){
	 				j=j+(((v[1]*v[2])%mod)*((v[1]*v[0])%mod))%mod;
	 				j=j%mod;
	 			}
	 			if(i==2){
	 				j=j+(((v[2]*v[1])%mod)*((v[2]*v[0])%mod))%mod;
	 				j=j%mod;
	 			}
	 		}
	 		return j;
	 	}
	 	if(unvis==1){
	 		return (((v[0]*v[1])%mod)*(n-1)+(v[0]*v[1])%mod)%mod;
	 	}
	 	if(unvis==2){
	 		return ((v[0]*v[0])%mod+2*v[0])%mod;
	 	}
	 	return 1;
	}
	void connect(int x,int y){
		int i=getfat(x),j=getfat(y);
		fat[i]=j;
	}
	int getfat(int x){
		if(x==fat[x])return x;
		else return fat[x]=getfat(fat[x]);
	}
	void solve(){
		int n,i,j;
		cin>>n;
		vector<int>v1,v2;
		for(i=0;i<n-3;i++){
			cin>>j;
			v1.push_back(j);
		}
		for(i=0;i<n-3;i++){
			cin>>j;
			v2.push_back(j);
		}
		cout<<getNumberOfSpanningTrees(n,v1,v2)<<endl;
	}
}a;

int main(){
	a.solve();
	return 0;
}