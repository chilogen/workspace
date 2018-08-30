#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
using namespace std;
string s,ts;
LL vis[26]={0},deg[26],v[26],use[26]={0},len;
vector<LL>edges[26];
vector<LL>ans;
inline void connect(char a,char b){
	LL i=a-'a',j=b-'a';
	edges[i].push_back(j);
	edges[j].push_back(i);
	deg[j]++;
}
bool dfs(LL x,LL d){
	if(d>=9)return true;
	vector<LL>::iterator it=edges[x].begin();
	while(it!=edges[x].end()){
		if(use[*it]){
			it++;
			continue;
		}
		use[*it]=1;
		ans.push_back(*it);
		if(dfs(*it,d+1))return true;
		use[*it]=0;
		ans.pop_back();
		it++;
	}
	return false;
}
void print(){
	LL i,j;
	for(i=0,j=9;i<(LL)ans.size();i++,j--)v[ans[i]]=j;
	for(i=0;i<(LL)ts.length()-1;i++){
		cout<<ts[i];
		if(v[ts[i]-'a']>v[ts[i+1]-'a'])cout<<" > ";
		else if(v[ts[i]-'a']<v[ts[i+1]-'a'])cout<<" < ";
		else cout<<" = ";
	}
	cout<<ts[i]<<endl;
}
int main(){
	LL i,k;
	cin>>ts;
	for(i=0;i<(LL)ts.length();i++)vis[ts[i]-'a']=1;
	for(i=0,k=0;i<26;i++)if(vis[i]){
		k++;
		s+=('a'+i);
	}
	if(k!=10){
		cout<<"Impossible\n";
		return 0;
	}
	for(i=0;i<(LL)ts.length()-1;i++)
		connect(ts[i],ts[i+1]);
	for(i=0;i<26;i++)if(vis[i]&&deg[i]==0){
		use[i]=1;
		ans.push_back(i);
		if(dfs(i,0)){
			print();
			return 0;
		}
		ans.pop_back();
		use[i]=0;
	}
	ans.push_back(ts[0]-'a');
	use[ts[0]-'a']=1;
	if(dfs(ts[0]-'a',0))print();
	else cout<<"Impossible\n";
	return 0;
}