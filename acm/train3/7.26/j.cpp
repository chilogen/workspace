#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct trie{
	LL ch[10];
	trie(){
		memset(ch,-1,sizeof(ch));
	}
}node;
vector<trie>T;
LL root[30],cnt=0,vis[30]={0},n;
map<string,LL>ma;
string s[30];
vector<string>number[30];
vector<string>v[30];
void insert(string ts,LL x){
	LL i,j,p=root[x],len=ts.length();
	for(i=len-1;i>=0;i--){
		j=ts[i]-'0';
		if(T[p].ch[j]==-1){
			T[p].ch[j]=T.size();
			T.push_back(node);
		}
		p=T[p].ch[j];
	}
	v[x].push_back(ts);
}
bool query(string ts,LL x){
	LL i,j,p=root[x],len=ts.length();
	for(i=len-1;i>=0;i--){
		j=ts[i]-'0';
		if(T[p].ch[j]==-1)return false;
		p=T[p].ch[j];
	}
	return true;
}
bool cmp(string a,string b){
	LL i=a.length(),j=b.length();
	return i>j;
}
void solve(LL x){
	sort(number[x].begin(),number[x].end(),cmp);
	LL i,k=number[x].size();
	for(i=0;i<k;i++){
		if(query(number[x][i],x))continue;
		else insert(number[x][i],x);
	}
}
int main(){
	LL i,j,k,l,p;
	string ts;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>s[i]>>k;
		if(ma[s[i]]==0){
			ma[s[i]]=++cnt;
			root[ma[s[i]]]=T.size();
			T.push_back(node);
		}
		p=ma[s[i]];
		for(j=0;j<k;j++){
			cin>>ts;
			number[p].push_back(ts);
		}
	}
		cout<<cnt<<endl;
	for(i=0;i<n;i++){
		j=ma[s[i]];
		if(vis[j])continue;
		vis[j]=1;
		solve(j);
		k=v[j].size();
		cout<<s[i]<<" "<<k<<" ";
		for(l=0;l<k;l++){
			ts=v[j][l];
			cout<<ts<<" ";
		}
		cout<<endl;
	}
}