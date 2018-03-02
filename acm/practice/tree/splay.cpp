#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,s;
	node* ch[2];
	int cmp(int x){
		if(x==v)	return -1;
		else return x>v;
	}
	void maintain(){
		s=1;
		if(ch[0]!=NULL)	s+=ch[0]->s;
		if(ch[1]!=NULL)	s+=ch[1]->s;
	}
}
void rotate(node8 &o,int d){
	node* t=o->ch[!d];
	o->ch[!d]=t->ch[d];
	t->ch[d]=o;
	o->maintain();
	t->maintain();
	o=t;
}
int main(){

}