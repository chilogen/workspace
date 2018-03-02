#include <bits/stdc++.h>
using namespace std;
struct Node{
	Node* child[2];
	int r,v;
	Node(){
		child[0]=child[1]=NULL;
	}
	int cmp(int x) const{
		if(x==v)	return -1;
		return x>v;
	}
}*root;
//d=0-->left d=1-->right
void rotate(Node * &o,int d){
	Node *k=o->child[!d];
	o->child[!d]=k->child[d];
	k->child[d]=o;
	o=k;
}
void insert(Node* &o,int x){
	if(o==NULL){
		o=new Node();
		o->v=x;
		o->r=rand();
	}
	else{
		int d=o->cmp(x);
		insert(o->child[d],x);
		if(o->child[d]->r>o->r)
			rotate(o,d^1);
	}
}
void remove(Node* &o,int x){
	if(o==NULL)	return;
	int d=o->cmp(x);  
	if(d==-1){
		if(o->child[0]==NULL)	o=o->child[1];
		else if(o->child[1]==NULL)	o=o->child[0];
		else {
			int d2=(o->child[0]->r>o->child[1]->r?1:0);
			rotate(o,d2);
			remove(o->child[d2],x);
		}
	}
	else remove(o->child[d],x);
}
int find(Node* o,int x){
	while(o!=NULL){
		int d=o->cmp(x);
		if(d==-1)	return 1;
		else o=o->child[d];
	}
	return 0;
}
int main(){
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j;
		insert(root,j);
	}
	remove(root,6);
	return 0;
}