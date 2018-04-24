#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
	node* ch[2];
	LL v,ln,rn;
	void maintain(){
		ln=ch[0]==NULL?0:ch[0]->ln+ch[0]->rn+1;
		rn=ch[1]==NULL?0:ch[1]->ln+ch[1]->rn+1;
	}
	node(){v=ln=rn=0;ch[0]=ch[1]=NULL;}
}*root1,*root2;
void build(node* o,LL* a,LL num){
	LL mid=num>>1,l=mid,r=num-mid-1;
	o->v=a[mid];o->ln=l;o->rn=r;
	if(l>0){
		o->ch[0]=new node();
		build(o->ch[0],a,l);
	}
	if(r>0){
		o->ch[1]=new node();
		build(o->ch[1],a+mid+1,r);
	}
}
void rotate(node* &o,LL d){
	node *k=o->ch[!d];
	o->ch[!d]=k->ch[d];
	o->maintain();
	k->ch[d]=o;
	o=k;
	o->maintain();
}
void splay(node* &o,LL k){
	if(k==o->ln+1)return;
	if(k<=o->ln){
		splay(o->ch[0],k);
		rotate(o,1);
	}
	else{
		splay(o->ch[1],k-o->ln-1);
		rotate(o,0);
	}
}
node* merge(node* a,node* b){
	splay(a,a->ln+a->rn+1);
	a->ch[1]=b;
	a->maintain();
	return a;
}
void split(node* o,LL k,node* &left,node* &right){
	splay(o,k);
	left=o;
	right=o->ch[1];
	o->ch[1]=NULL;
	o->maintain();
}
int main(){
	LL a[10],i;
	for(i=0;i<10;i++)cin>>a[i];
	sort(a,a+10);
	root1=new node();
	root2=new node();
	build(root1,a,5);
	build(root2,a+5,5);
	root1=merge(root1,root2);
	split(root1,6,root1,root2);
	return 0;
}