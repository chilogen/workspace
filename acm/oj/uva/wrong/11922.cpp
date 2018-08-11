/*
something confusing of running time
it seem similar between commented part and uncommented part
bu it take lot of time to run the commented part
but the time complexity should be nlog(n)
*/

/*
update: ac on 320ms,it seem the data not so strong
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[100010];
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
	o->v=a[mid32];o->ln=l;o->rn=r;
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
	if(k==0){
		left=NULL;
		right=o;
		return;
	}
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
	cout<<o->v<<endl;
	output(o->ch[1]);
}
int main(){
	LL i,j,k;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(i=0;i<n;i++)a[i]=i+1;
	p1=new node();
	build(p1,a,n);
	for(i=0;i<m;i++){/*
		cin>>j>>k;
		if(j==k)continue;
		split(p1,k,mid,p2);
		split(mid,j-1,p1,mid);
		mid->flip^=1;
		if(p1==NULL)p1=p2;
		else p1=merge(p1,p2);
		if(p1==NULL)p1=mid;
		else p1=merge(p1,mid);*/
		j=rand()%50000;
		if(j==0)j=j+1;
		j=abs(j);
		split(p1,j,p1,p2);
		p1->flip^=1;
		p1=merge(p1,p2);
		j=rand()%50000;
		if(j==0)j=j+1;
		j=abs(j);
		split(p1,j,p1,p2);
		p1=merge(p1,p2);
	}
	output(p1);
	return 0;
}