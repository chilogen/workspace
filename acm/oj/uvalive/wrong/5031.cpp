#include <bits/stdc++.h>
using namespace std;
#define Maxnode 20010
#define Maxcmd	500010
#define MAxedge	60010
typedef long long LL;
struct Rank
{
	LL v,r,s;
	Rank* ch[2];
	LL cmp(LL x){
		if(x==v)	return -1;
		else return x<v;
	}
	void maintain(){
		s=1;
		if(ch[0]!=NULL)	s+=ch[0]->s;
		if(ch[1]!=NULL)	s+=ch[1]->s;	}
}* root[Maxnode];
struct edge{
	LL u,v;
}e[MAxedge];
struct cmd{
	char oper;
	LL a,b;
}c[Maxcmd];
LL fat[Maxnode],weight[Maxnode],numofcmd,n,m;
double ans,numofq;
bool vis[MAxedge];

LL getfat(LL x){
	if(x==fat[x])	return x;
	else return fat[x]=getfat(fat[x]);
}

void rotate(Rank* &o,LL d){
	Rank* temp=o->ch[d^1];
	o->ch[d^1]=temp->ch[d];
	temp->ch[d]=o;
	o->maintain();
	temp->maintain();
	o=temp;
}

void insert(Rank* &o,LL x){
	if(o==NULL){
		o=new Rank();
		o->v=x;	o->r=rand();	o->s=1;
		return;
	}
	LL d=o->cmp(x);
	if(d==-1)	d=0;
	insert(o->ch[d],x);
	if(o->ch[d]->r>o->r)	rotate(o,d^1);
	o->maintain();
}

void remove(Rank* &o,LL x){
	LL d=o->cmp(x);
	if(d==-1){
		Rank *tmp=o;
		if(o->ch[0]==NULL){o=o->ch[1];delete tmp;return;}
		if(o->ch[1]==NULL){o=o->ch[0];delete tmp;return;}
		d=o->ch[0]->r>o->ch[1]->r;
		rotate(o,d);
		remove(o->ch[d],x);
	}
	else remove(o->ch[d],x);
	o->maintain();
}

void Union(LL j,LL k){
	while(root[j]!=NULL){
		insert(root[k],root[j]->v);
		remove(root[j],root[j]->v);
	}
}

LL kth(Rank *o,LL x){
	LL l;
	if(o==NULL)	return 0;
	if(o->ch[0]==NULL)	l=0;
	else l=o->ch[0]->s;
	if(x-l==1)	return o->v;
	if(x-l<1)	return kth(o->ch[0],x);
	else	return kth(o->ch[1],x-l-1);
}

void restore(Rank *x){
	if(x==NULL)	return;
	if(x->ch[0]!=NULL)	restore(x->ch[0]);
	if(x->ch[1]!=NULL)	restore(x->ch[1]);
	delete(x);
}

int main(){
	LL i,j,k,Kase=1;
	ios::sync_with_stdio(false);
	while(1){
		cin>>n>>m;
		if(n==m&&n==0)	break;
		for(i=0;i<Maxnode;i++){
			restore(root[i]);
			root[i]=NULL;
			fat[i]=i;
		}
		numofq=0;	numofcmd=0;	ans=0;
		memset(vis,0,sizeof(vis));

		for(i=0;i<n;i++){
			cin>>weight[i+1];
		}
		for(i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v;
		}
		while(cin>>c[numofcmd].oper){
			if(c[numofcmd].oper=='E')	break;
			if(c[numofcmd].oper=='D'){
				cin>>c[numofcmd].a;
				vis[c[numofcmd].a]=1;
			}
			if(c[numofcmd].oper=='C'){
				cin>>c[numofcmd].a>>c[numofcmd].b;
				i=weight[c[numofcmd].a];
				weight[c[numofcmd].a]=c[numofcmd].b;
				c[numofcmd].b=i;
			}
			if(c[numofcmd].oper=='Q'){
				cin>>c[numofcmd].a>>c[numofcmd].b;
				numofq++;
			}
			numofcmd++;
		}
		for(i=1;i<=m;i++){
			if(!vis[i]){
				j=getfat(e[i].u);
				fat[e[i].v]=j;
			}
			/*
			if(!vis[i]){
				j=getfat(e[i].u);
				k=getfat(e[i].v);
				fat[k]=j;
			}---->>>right
			*/
		}
		for(i=1;i<=n;i++){
			j=getfat(i);
			insert(root[j],weight[i]);
		}
		for(i=numofcmd-1;i>=0;i--){
			if(c[i].oper=='D'){
				edge &te=e[c[i].a];
				j=getfat(te.u);
				k=getfat(te.v);
				if(j==k)	continue;
				if(root[j]->s>root[k]->s){
					Union(k,j);
					fat[k]=j;
				}
				else{
					Union(j,k);
					fat[j]=k;
				}
			}
			if(c[i].oper=='Q'){
				j=getfat(c[i].a);
				ans+=kth(root[j],c[i].b);
			}
			if(c[i].oper=='C'){
				j=getfat(c[i].a);
				remove(root[j],weight[c[i].a]);
				weight[c[i].a]=c[i].b;
				insert(root[j],weight[c[i].a]);
			}
		}
		printf("Case %lld: %.10lf\n",kase,ans/numofquery);
		//printf("Case %lld: %.6lf\n",Kase++,ans/numofq);-->>right....................!!!!!!!!!!!!!
	}
	return 0;
}