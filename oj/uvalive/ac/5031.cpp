#include <bits/stdc++.h>
#define MXnode	20010
#define MXedge	60010
#define MXcmd	500010
using namespace std;
typedef long long LL;
struct node{
	LL v,r,s;
	node *ch[2];
	int cmp(LL x){
		if(x==this->v)	return -1;
		return x<this->v;
	}
	void maintain(){
		s=1;
		if(ch[0]!=NULL)	s+=ch[0]->s;
		if(ch[1]!=NULL)	s+=ch[1]->s;
	}
}* root[MXnode];
struct{char c;LL a,b;}cmd[MXcmd];
struct edge{LL u,v;}te;
vector<edge>e;
bool vis[MXedge];
LL w[MXnode],fat[MXnode],n,m,sum,numofcmd;
LL getfat(LL x){
	if(x==fat[x])	return x;
	else return fat[x]=getfat(fat[x]);
}
void restore(node* o){
	if(o==NULL)	return ;
	if(o->ch[0]!=NULL)	restore(o->ch[0]);
	if(o->ch[1]!=NULL)	restore(o->ch[1]);
	delete o;
	o=NULL;
}
void rotate(node* &o,LL d){
	node *t=o->ch[!d];
	o->ch[!d]=t->ch[d];
	t->ch[d]=o;
	o->maintain();
	t->maintain();
	o=t;
}
void insert(node* &o,LL x){
	if(o==NULL){
		o=new node();
		o->s=1;o->r=rand();o->v=x;
		return;
	}
	LL d=o->cmp(x);
	if(d==-1)	d=0;
	insert(o->ch[d],x);
	if(o->ch[d]->r>o->r)	rotate(o,!d);
	o->maintain();
}
void remove(node* &o,LL x){
	LL d=o->cmp(x);
	if(d==-1){
		node* tmp=o;
		if(o->ch[0]==NULL)	{o=o->ch[1];delete tmp;return;}
		if(o->ch[1]==NULL)	{o=o->ch[0];delete tmp;return;}
		d=o->ch[0]->r>o->ch[1]->r;
		rotate(o,d);
		remove(o->ch[d],x);
	}
	else remove(o->ch[d],x);
	if(o!=NULL) o->maintain();
}
void merge(node* &j,node* &k){
	if(j->ch[0]!=NULL)	merge(j->ch[0],k);
	if(j->ch[1]!=NULL)	merge(j->ch[1],k);
	insert(k,j->v);
	delete j;
	j=NULL;
}
LL kth(node* o,LL x){
	LL l=0;
	if(o==NULL)	return 0;
	if(o->ch[0]!=NULL)	l=o->ch[0]->s;
	if(x-l==1)	return o->v;
	if(x-l<1)	return kth(o->ch[0],x);
	return kth(o->ch[1],x-l-1);
}
int main(){
	LL i,j,k,kase=0;
	double ans,numofquery;
	ios::sync_with_stdio(false);
	while(cin>>n>>m){
		kase++;	ans=0;
		memset(vis,0,sizeof(vis));
		if(n==m&&n==0)	break;
		for(i=1;i<=n;i++){
			cin>>w[i];	
			fat[i]=i;
			restore(root[i]);
			root[i]=NULL;
		}
		e.clear();
		e.push_back(te);
		for(i=1;i<=m;i++){
			cin>>te.u>>te.v;
			e.push_back(te);
		}
		for(numofcmd=0,numofquery=0;;numofcmd++){
			cin>>cmd[numofcmd].c;
			if(cmd[numofcmd].c=='D'){
				cin>>cmd[numofcmd].a;
				vis[cmd[numofcmd].a]=1;
			}
			if(cmd[numofcmd].c=='C'){
				cin>>cmd[numofcmd].a;
				cmd[numofcmd].b=w[cmd[numofcmd].a];
				cin>>w[cmd[numofcmd].a];
			}
			if(cmd[numofcmd].c=='Q'){
				cin>>cmd[numofcmd].a>>cmd[numofcmd].b;
				numofquery++;
			}
			if(cmd[numofcmd].c=='E')	break;
		}
		for(i=1;i<=m;i++)
			if(!vis[i]){
				j=getfat(e[i].u);
				k=getfat(e[i].v);
				fat[k]=j;
			}
		for(i=1;i<=n;i++){
			j=getfat(i);
			insert(root[j],w[i]);
		}
		numofcmd--;
		for(;numofcmd>=0;numofcmd--){
			if(cmd[numofcmd].c=='D'){
				i=cmd[numofcmd].a;
				j=getfat(e[i].u);
				k=getfat(e[i].v);
				if(j==k)	continue;
				if(root[j]->s<root[k]->s){
					merge(root[j],root[k]);
					fat[j]=k;
				}
				else{
					merge(root[k],root[j]);
					fat[k]=j;
				}
			}
			if(cmd[numofcmd].c=='C'){
				i=getfat(cmd[numofcmd].a);
				remove(root[i],w[cmd[numofcmd].a]);
				w[cmd[numofcmd].a]=cmd[numofcmd].b;
				insert(root[i],w[cmd[numofcmd].a]);
			}
			if(cmd[numofcmd].c=='Q'){
				i=getfat(cmd[numofcmd].a);
				ans+=kth(root[i],cmd[numofcmd].b);
			}
		}
		printf("Case %lld: %.6lf\n",kase,ans/numofquery);
	}
	return 0;
}