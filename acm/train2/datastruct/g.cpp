#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
queue<pair<LL,LL>>q;
queue<LL>ind;
LL n,j,t,a,b,T;
int main(){
	cin>>n;
	while(n--){
		cin>>j;
		switch(j){
			case 1:{
				cin>>t>>a>>b;
				ind.push(a);
				q.push(make_pair(t,t+b));
				break;
			}
			case 2:{
				cin>>t;
				while(!q.empty()){
					if(t<q.front().first)break;
					if(t<q.front().second){
						ind.pop();q.pop();
						break;
					}
					ind.pop();q.pop();
				}
				break;
			}
			case 3:{
				cin>>t;
				if(q.empty()){
					cout<<-1<<endl;
					break;
				}
				while(!q.empty()){
					if(t<q.front().first){
						cout<<-1<<endl;
						break;
					}	
					if(t<q.front().second){
						cout<<ind.front()<<endl;
						break;
					}
					ind.pop();q.pop();
					if(q.empty())cout<<-1<<endl;
				}
				break;
			}
		}
	}
	return 0;
}