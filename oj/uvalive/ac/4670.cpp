#include <bits/stdc++.h>
using namespace std;
#define Mxnode 11000
#define Sigma 26
#define reset(a,b)	memset(a,b,sizeof(a))
#define copy(a,b)	memcpy(a,b.c_str(),sizeof(char)*b.length());
int freq[200],n;
string s[200];
char c[1000010];
class Trie{
private:
	int ch[Mxnode][Sigma],sz,fail[Mxnode],last[Mxnode];
	vector<int>v[Mxnode];
	int idx(char c){return c-'a';}
	void getfail(){
		int i,j,k;
		queue<int>q;
		for(i=0;i<Sigma;i++){
			if(ch[0][i])q.push(ch[0][i]);
		}
		while(!q.empty()){
			i=q.front();q.pop();
			k=fail[i];
			for(j=0;j<26;j++){
				if(!ch[i][j])continue;
				q.push(ch[i][j]);
				while(k&&!ch[k][j])k=fail[k];
				fail[ch[i][j]]=ch[k][j];
				last[ch[i][j]]=v[ch[k][j]].size()?ch[k][j]:last[ch[k][j]];
			}
		}
	}
	void add(int x){
		vector<int>::iterator p=v[x].begin();
		while(p!=v[x].end()){
			freq[*p]++;
			p++;
		}
	}
public:
	Trie(){
		reset(ch,0);
		reset(fail,0);
		reset(last,0);
		sz=0;
	}
	void insert(char *s,int x){
		int i,j,k,len=strlen(s);
		for(i=0,k=0;i<len;i++){
			j=idx(s[i]);
			if(!ch[k][j])ch[k][j]=++sz;
			k=ch[k][j];
		}
		v[k].push_back(x);
	}
	void find(char *s,int len){
		int i,j,k;
		getfail();
		for(i=0,k=0;i<len;i++){
			j=idx(s[i]);
			while(k&&!ch[k][j])k=fail[k];
			k=ch[k][j];
			if(v[k].size()!=0)add(k);
			if(v[last[k]].size()!=0)add(last[k]);
		}
	}
}*p;
inline void init(){
	reset(freq,0);
	p=new Trie();
}
int main(){
	int i,j;
	while(cin>>n){
		if(n==0)break;
		init();
		for(i=0;i<n;i++){
			cin>>s[i];
			reset(c,0);
			copy(c,s[i]);
			p->insert(c,i);
		}
		cin>>s[199];
		reset(c,0);
		copy(c,s[199]);
		p->find(c,s[199].length());
		for(i=0,j=0;i<n;i++){if(freq[i]>j)j=freq[i];}
		cout<<j<<endl;
		for(i=0;i<n;i++){if(freq[i]==j)cout<<s[i]<<endl;}
		delete p;
	}
	return 0;
}