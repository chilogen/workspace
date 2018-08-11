#include <bits/stdc++.h>
using namespace std;
#define Pi pair<int,int>
#define mp(a,b)	make_pair(a,b)
#define pb(x)	push_back(x)
#define reset(a,b)	memset(a,b,sizeof(a))
vector<Pi >v;
Pi tmp;
int ans[3100],n;
int cross(Pi a,Pi b,Pi c,Pi d){
	int x1=b.first-a.first,y1=b.second-a.second;
	int x2=d.first-c.first,y2=d.second-c.second;
	int z=x1*y2-y1*x2;
	return z;
}
bool cmp(Pi a,Pi b){
	int z=cross(tmp,a,tmp,b);
	if(z<=0)	return false;
	return true;
}
void solve(int x){
	int i=2,j,k=x+1;
	stack<int>s;
	s.push(x);k%=n;s.push(k);
	while(i<=n){
		i++;
		j=s.top();s.pop();k=(j+1)%n;
		int z=cross(v[s.top()],v[j],v[j],v[k]);
		if(z>=0)s.push(j);
		s.push(k);
	}
	i=n-s.size();
	while(!s.empty()){
		if(ans[s.top()]==-1)	ans[s.top()]=i;
		s.pop();
	}
}
int main(){
	int i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j>>k;
		v.pb(mp(j,k));
	}
	if(n<=3){
		cout<<0<<endl;
		return 0;
	}
	sort(v.begin(),v.end(),cmp);
	reset(ans,-1);
	for(i=0;i<n;i++){
		if(ans[i]!=-1)continue;
		tmp=v[i];
		sort(v.begin(),v.end(),cmp);
		solve(i);
	}
	for(i=0;i<n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
