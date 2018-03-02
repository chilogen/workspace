#include <bits/stdc++.h>
using namespace std;
#define MXnode 100000
#define sigma 26
#define reset(a,b)	memset(a,b,sizeof(a))
string str[100];
struct Trie{
	int ch[MXnode][sigma];
	int fail[MXnode],last[MXnode];
	vector<int>v[MXnode];
	int sz;
	Trie(){
		sz=0;
		reset(ch,0);reset(fail,0);
		reset(last,0);reset(v,0);
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
	void getfail(){
		int i,j,k;
		queue<int>q;
		for(i=0;i<sigma;i++){
			if(ch[0][i])q.push(ch[0][i]);
		}
		while(!q.empty()){
			k=q.front();q.pop();
			j=fail[k];
			for(i=0;i<sigma;i++){
				if(!ch[k][i])continue;
				q.push(ch[k][i]);
				while(j&&!ch[j][i])j=fail[j];
				fail[ch[k][i]]=ch[j][i];
				if(v[fail[ch[k][i]]].size()!=0)last[ch[k][i]]=ch[j][i];
				else last[ch[k][i]]=last[fail[ch[j][i]]];
			}
		}
	}
	void find(char *s){
		int i,j,k,len=strlen(s);
		for(i=0,k=0;i<len;i++){
			j=idx(s[i]);
			while(k&&!ch[k][j])k=fail[k];
			k=ch[k][j];
			if(v[k].size()!=0)print(v[k],i);
			if(v[last[k]].size()!=0)print(v[last[k]],i);
		}
	}
	void print(vector<int>&a,int x){
		vector<int>::iterator p=a.begin();
		for(;p!=a.end();p++){
			cout<<"find "<<str[*p]<<" at "<<x-str[*p].length()+2<<endl;
		}
		cout<<endl;
	}
	int idx(char c){return c-'a';}
}T;
int main(){
	int n,i,j;
	string s;
	char c[1000];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>str[i];
		reset(c,0);
		memcpy(c,str[i].c_str(),str[i].length());
		T.insert(c,i);
	}
	T.getfail();
	cin>>s;
	memcpy(c,s.c_str(),s.length());
	T.find(c);
	return 0;
}