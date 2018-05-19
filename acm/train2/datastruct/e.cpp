#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<string,LL>psl;
typedef map<string,LL>msl;
struct cmp{
	bool less;
	cmp(const bool &a=false){
		less=a;
	}
	bool operator()(const psl &a,const psl &b){
		if(less)return a.second<b.second;
		else return b.second<a.second;
	}
};
typedef  priority_queue<psl,vector<psl>,cmp> pcmp;
pcmp lowest,highest(true);
msl m;
LL n,c,y;
string x;
int main(){
	psl tmp;
	cin>>n;
	while(n--){
		cin>>c;
		switch(c){
			case 1:{
				cin>>x>>y;
				if(m[x]!=0)break;
				highest.push(make_pair(x,y));
				lowest.push(make_pair(x,y));
				m[x]=y;
				break;
			}
			case 2:{
				cin>>x;
				m[x]=0;
				break;
			}
			case 3:{
				cin>>x>>y;
				if(m[x]!=0){
					highest.push(make_pair(x,y));
					lowest.push(make_pair(x,y));
					m[x]=y;
				}
				break;
			}
			case 4:{
				cin>>y;
				if(y==1){
					while(1){
						if(lowest.empty())break;
						tmp=lowest.top();
						if(m[tmp.first]!=tmp.second)lowest.pop();
						else{
							cout<<tmp.first<<endl;
							break;
						}
					}
				}
				if(y==2){
					while(1){
						if(highest.empty())break;
						tmp=highest.top();
						if(m[tmp.first]!=tmp.second)highest.pop();
						else{
							cout<<tmp.first<<endl;
							break;
						}
					}
				}
				break;
			}
		}
	}
	return 0;
}