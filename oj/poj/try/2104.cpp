#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
	LL v[4];//ind->0 s->1 v->2 r->3
	node* ch[2];
	node(LL x,LL ind){
		v[0]=ind; v[1]=1; v[2]=x; v[3]=rand();
		ch[0]=ch[1]=NULL;
	}
	void maintain(){
		v[1]=1;
		if(ch[0]!=NULL)	v[1]+=ch[0]->v[1];
		if(ch[1]!=NULL)	v[2]+=ch[1]->v[1];
	}
	LL cmp(LL x,k){
		LL t=v[k];
		if(x==t)	return -1;
		return x>t;
	}
}* root;
void insert(node* &o,LL v,LL ind){
	if(o==NULL){
		o=new node(v,ind);
		return;
	}
	LL d=o->cmp(v,2);
	insert(o->ch[d],v,ind);
	if(o->ch[d]->r>o->r)	rotate(o,!d);
}
node* splay(){}
void query(){}
LL n,m;
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	LL i,j,l,r,k;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>j;
		insert(root,j,i);
	}
	for(i=0;i<m;i++){
		cin>>l>>r>>k;
		node* tmp1=splay(root,l);
		ndoe* tmp2=splay(tmp->ch[1],r);
		cout<<query(tmp2->ch[0],k)<<endl;
	}
	return 0;
}