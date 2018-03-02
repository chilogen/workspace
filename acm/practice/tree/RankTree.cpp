//application of Treap(find the K_th value)

#include <bits/stdc++.h>
using namespace std;
struct Mset{
	int v,s,r;
	Mset* ch[2];
	void maintain(){
		int x=0;
		if(this->ch[0]!=NULL)	x+=this->ch[0]->s;
		if(this->ch[1]!=NULL)	x+=this->ch[1]->s;
		this->s=x+1;
	}
	int cmp(int x){
		if(x==v)	return -1;
		else return x>v;
	}
	Mset(){
		v=s=r=0;
		ch[0]=ch[1]=0;
	}
}*root;
void rotate(Mset* &o,int d){
	Mset* temp=o->ch[d^1];
	o->ch[d^1]=temp->ch[d];
	temp->ch[d]=o;
	o->maintain();
	temp->maintain();
	o=temp;
}
void insert(Mset* &o,int x){
	if(o==NULL){
		o=new Mset();
		o->v=x;	o->s=1;	o->r=rand();
		return;
	}
	int d=o->cmp(x);
	insert(o->ch[d],x);
	o->maintain();
	if(o->ch[d]->r>o->r)	rotate(o,d^1);
}
bool in(Mset* &o,int x){
	while(o!=NULL){
		int d=o->cmp(x);
		if(d==-1)	return 1;
		o=o->ch[d];
	}
	return 0;
}
void remove(Mset* &o,int x){
	int d=o->cmp(x);
	if(d==-1){
		if(o->ch[0]==NULL){o=o->ch[1];	return;}
		else if(o->ch[1]==NULL){o=o->ch[0];	return;}
		else{
			d=o->ch[0]->r>o->ch[1]->r;
			rotate(o,d);
			remove(o->ch[d],x);
		}
	}
	else remove(o->ch[d],x);
	o->maintain();
}

//that's it
int getkth(Mset* o,int x){
	int l,r;
	if(o->ch[0]==NULL)	l=0;
	else l=o->ch[0]->s;
	if(x-l==1)	return o->v;
	if(x-l>1)	return getkth(o->ch[1],x-l-1);
	else 		return getkth(o->ch[0],x);

}
int main(){
	int n,i,j;  
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j;
		insert(root,j);
	}
	cout<<getkth(root,5)<<endl;
	/*
	cout<<in(root,8)<<endl;
	remove(root,8);
	cout<<in(root,8)<<endl;
	*/
	return 0;
}