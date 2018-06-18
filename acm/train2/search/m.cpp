#include <bits/stdc++.h>
using namespace std;
#define MXnode 510000
#define sigma 26
#define reset(a,b)	memset(a,b,sizeof(a))
char s[1000010],pattern[60];
int t,n,ans;

int ch[MXnode][sigma];
int fail[MXnode],last[MXnode],val[MXnode];
int sz;
queue<int>q;

void init(){
	sz=0;
	reset(ch[0],0);
	reset(fail,0);
	reset(last,0);reset(s,0);
	reset(val,0);
	ans=0;
}

void insert(char *s){
	int i,j,k,len=strlen(s);
	for(i=0,k=0;i<len;i++){
		j=s[i]-'a';
		if(!ch[k][j]){
			ch[k][j]=++sz;
			reset(ch[sz],0);
		}
		k=ch[k][j];
	}
	val[k]++;
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
			if(val[fail[ch[k][i]]]!=0)last[ch[k][i]]=ch[j][i];
			else last[ch[k][i]]=last[fail[ch[k][i]]];
		}
	}
}
void add(int x){
	while(x){
		ans+=val[x];
		x=last[x];
	}
}

void find(char *s){
	int i,j,k,len=strlen(s);
	for(i=0,k=0;i<len;i++){
		j=s[i]-'a';
		while(k&&!ch[k][j])k=fail[k];
		k=ch[k][j];
		add(k);
	}
}
int main(){
	int i;
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%s%d",s,&n);
		for(i=0;i<n;i++){
			reset(pattern,0);
			scanf("%s",pattern);
			insert(pattern);
		}
		getfail();
		find(s);
		printf("%d\n",ans);
	}
	return 0;
}