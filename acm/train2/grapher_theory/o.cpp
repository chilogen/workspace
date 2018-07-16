#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
vector<pair<int,int> >e;
vector<int>v[maxn];
stack<int>s;
int vis[2*maxn]={0},deg[maxn]={0},n,m;
inline void connect(int a,int b){
	e.push_back(make_pair(a,b));
	e.push_back(make_pair(b,a));
	v[a].push_back(e.size()-2);
	v[b].push_back(e.size()-1);
	deg[a]++;deg[b]++;
}
int main(){
	int i,j,l,a,b;
	vector<int>o;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		connect(a,b);
	}
	for(i=0;i<n;i++)if(deg[i]%2!=0)o.push_back(i);
	if(o.size()>2){cout<<"No\n";return 0;}
	i=0;
	if(o.size()==2)i=o[0];
	s.push(i);
	cout<<"Yes\n";
	while(!s.empty()){
		j=s.top();
		vector<int>::reverse_iterator p;
		l=0;
		while(!v[j].empty()){
			p=v[j].rbegin();
			if(vis[(*p)/2]){v[j].pop_back();continue;}
			vis[(*p)/2]=1;v[j].pop_back();
			s.push(e[*p].second);
			l=1;
			break;
		}
		if(l==1)continue;
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}