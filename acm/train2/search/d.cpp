#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define sigma 26
#define reset(a,b)	memset(a,b,sizeof(a))
char s[maxn],pattern[maxn];
int t,n,query[maxn],len[maxn];

int ch[maxn][sigma];
int fail[maxn],last[maxn];
vector<int>val[maxn],ans[maxn];
int sz;
queue<int>q;

void init(){
	sz=0;
	reset(ch[0],0);
	reset(fail,0);
	reset(last,0);reset(s,0);
}

void insert(char *s,int x){
	int i,j,k,len=strlen(s);
	for(i=0,k=0;i<len;i++){
		j=s[i]-'a';
		if(!ch[k][j]){
			ch[k][j]=++sz;
			reset(ch[sz],0);
		}
		k=ch[k][j];
	}
	val[k].push_back(x);
}
	
void getfail(){
	int i,j,k;
	for(i=0;i<sigma;i++)	if(ch[0][i])q.push(ch[0][i]);
	while(!q.empty()){
		k=q.front();q.pop();
		for(i=0;i<sigma;i++){
			if(!ch[k][i])continue;
			j=fail[k];
			q.push(ch[k][i]);
			while(j&&!ch[j][i])j=fail[j];
			fail[ch[k][i]]=ch[j][i];
			if(val[fail[ch[k][i]]].size()!=0)last[ch[k][i]]=ch[j][i];
			else last[ch[k][i]]=last[fail[ch[k][i]]];
		}
	}
}
void add(int x,int y){
	while(x){
		vector<int>::iterator p=val[x].begin();
		while(p!=val[x].end()){
			ans[*p].push_back(y);
			p++;
		}
		x=last[x];
	}
}

void find(char *s){
	int i,j,k,len=strlen(s);
	for(i=0,k=0;i<len;i++){
		j=s[i]-'a';
		while(k&&!ch[k][j])k=fail[k];
		k=ch[k][j];
		add(k,i);
	}
}
int main(){
	int i,j,k,tans;
	scanf("%s%d",s,&n);
	for(i=0;i<n;i++){
		reset(pattern,0);
		scanf("%d%s",&query[i],pattern);
		insert(pattern,i);
		len[i]=strlen(pattern);
	}
	getfail();
	find(s);
	for(i=0;i<n;i++){
		tans=maxn;
		for(j=0,k=j+query[i]-1;k<(int)ans[i].size();j++,k++){
			tans=min(tans,ans[i][k]-ans[i][j]+len[i]);
		}
		if(tans==maxn)printf("-1\n");
		else printf("%d\n",tans);
	}
	return 0;
}