#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[100010];
bool out=false;
struct node{
	node* ch[2];
	LL v,ln,rn,flip;
	void maintain(){
		ln=ch[0]==NULL?0:ch[0]->ln+ch[0]->rn+1;
		rn=ch[1]==NULL?0:ch[1]->ln+ch[1]->rn+1;
	}
	void pushdown(){
		if(flip){
			swap(ch[0],ch[1]);
			swap(ln,rn);
			flip=0;
			if(ch[0]!=NULL)ch[0]->flip=!ch[0]->flip;
			if(ch[1]!=NULL)ch[1]->flip=!ch[1]->flip;
		}
	}
	node(){v=ln=rn=flip=0;ch[0]=ch[1]=NULL;}
}*p1,*mid,*p2;
void build(node* o,LL* a,LL num){
	LL mid=num>>1,l=mid,r=num-mid-1;
	if(l>0){
		o->ch[0]=new node();
		build(o->ch[0],a,l);
	}
	o->v=a[mid];o->ln=l;o->rn=r;
	if(r>0){
		o->ch[1]=new node();
		build(o->ch[1],a+mid+1,r);
	}
}
void rotate(node* &o,LL d){
	node* k=o->ch[!d];
	o->ch[!d]=k->ch[d];
	o->maintain();
	k->ch[d]=o;
	o=k;
	o->maintain();
}
void splay(node* &o,LL k){
	o->pushdown();
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
	if(a==NULL)return b;
	splay(a,a->ln+a->rn+1);
	a->ch[1]=b;
	a->maintain();
	return a;
}
void split(node* o,LL k,node* &left,node* &right){
	splay(o,k);
	left=o;
	right=o->ch[1]; 
	left->ch[1]=NULL;
	left->maintain();
	if(right!=NULL)right->maintain();
}
void output(node* o){
	if(o==NULL)return;
	o->pushdown();
	output(o->ch[0]);
	if(out)cout<<o->v<<endl;
	out=true;
	output(o->ch[1]);
}
int main(){
	LL i,j,k;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(i=0;i<=n;i++)a[i]=i;
	p1=new node();
	build(p1,a,n+1);
	for(i=0;i<m;i++){
		cin>>j>>k;
		split(p1,j,p1,p2);
		split(p2,k-j+1,mid,p2);
		mid->flip^=1;
		p1=merge(p1,p2);
		p1=merge(p1,mid);
	}
	output(p1);
	return 0;
}