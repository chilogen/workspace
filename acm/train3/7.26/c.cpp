#include <bits/stdc++.h>
using namespace std;
const int maxbit=30;
struct node{
	node *ch[2];
	int cnt[2];
	node(){
		ch[0]=ch[1]=NULL;
		cnt[0]=cnt[1]=0;
	}
}*root;

string s;
void insert(){
	node *p=root;
	int j,k=0;
	while(k<maxbit){
		j=s[k]-'0';
		p->cnt[j]++;
		if(p->ch[j]==NULL)p->ch[j]=new node();
		p=p->ch[j];
		k++;
	}
}
void dfs(node *p,int k,int &ans){
	if(k>=maxbit)return;
	int j=s[k]-'0',i=j;
	if(p->cnt[j]==0)j=!j;
	p->cnt[j]--;
	ans^=((i^j)<<(maxbit-k-1));
	dfs(p->ch[j],k+1,ans);
	if(p->cnt[j]==0)delete p->ch[j];
}
void match(int &ans){
	ans=0;
	dfs(root,0,ans);
}
void getss(int x){
	s="";
	while(x){
		if(x&1)s+='1';
		else s+='0';
		x=x>>1;
	}
	while(s.length()<maxbit)s+='0';
	reverse(s.begin(),s.end());
}
int v[300010];
int main(){
	root=new node();
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>v[i];
	}
	for(i=0;i<n;i++){
		cin>>j;
		getss(j);
		insert();
	}
	for(i=0;i<n;i++){
		getss(v[i]);
		match(j);
		cout<<j<<" ";
	}
	return 0;
}