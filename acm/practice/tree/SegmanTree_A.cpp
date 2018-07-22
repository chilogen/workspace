//bo done yet


/*
segment tree template
function
	query return the left/right most val pos equal to flag,if don't have one,return -1
variable
	"l,r",lazy is the same as normal segment tree
	"f" is the value of each node(minum,maxnum....)
	have is mark the this subtree have the val which equal to the flag
midify:
	focus on every comment
sources:
	Gym 101102k,and run on vjudge at top 40(4118ms)
	solution path:acm/train3/7.18/d.cpp
	after add general code:
		f-fun()	+300ms
		Leftmost and Right most -300ms

*/


#include <bits/stdc++.h>
using namespace std;


//decide to query left first or right first
//#define LeftMost
#define RightMost

//decide to no to use "have" mark
#define MinMax

//basic data type
typedef long long Int;

//the value show be equal
const Int flag=0;

//determine the variable f,to run faster,try to insert this function manually to the codety
inline Int f_fun(Int a,Int b){return min(a,b);}

const Int maxn=1e5+10,inf=1e15;
vector<Int>e[maxn];
Int n,m,t,cnt[maxn];
struct node{
	Int l,r,lazy,f;

	//if just query "f" for min value or value value,don't need a "have" mark,just change the "f_fun()""
	//and delete the comment only MinMax

	Int have;
}T[maxn<<4];
void build(Int x,Int a,Int b){
	T[x].l=a;T[x].r=b;T[x].lazy=0;
	if(a==b){
		T[x].f=cnt[a];
		return;
	}
	Int mid=(a+b)>>1;
	build(x<<1,a,mid);
	build((x<<1)+1,mid+1,b);
	T[x].f=f_fun(T[x<<1].f,T[(x<<1)+1].f);

}
void pushdown(Int x);
void update(Int x,Int a,Int b,Int v){
	if(a>b)return;
	if(T[x].l>=a&&T[x].r<=b){
		T[x].lazy+=v;
		T[x].f+=v;
		return;
	}
	if(T[x].lazy!=0)pushdown(x);
	Int mid=(T[x].l+T[x].r)>>1;
	if(a<=mid)update(x<<1,a,b,v);
	if(b>mid)update((x<<1)+1,a,b,v);
	T[x].f=f_fun(T[x<<1].f,T[(x<<1)+1].f);
}
void pushdown(Int x){
	if(T[x].l!=T[x].r){
		update(x<<1,T[x].l,T[x].r,T[x].lazy);
		update((x<<1)+1,T[x].l,T[x].r,T[x].lazy);
		T[x].f=f_fun(T[x<<1].f,T[(x<<1)+1].f);
	}
	T[x].lazy=0;
}
Int query(Int x){
	Int i;
	if(T[x].l==T[x].r){
		T[x].f=inf;
		return T[x].r;
	}
	if(T[x].lazy!=0)pushdown(x);

	#ifdef RightMost
	if(T[(x<<1)+1].f==T[x].f)i=query((x<<1)+1);
	else if(T[x<<1].f==T[x].f) i=query(x<<1);
	#endif
	
	#ifdef LeftMost
	if(T[x<<1].f==T[x].f)i=query(x<<1);
	else if(T[(x<<1)+1].f==T[x].f) i=query((x<<1)+1);
	#endif

	T[x].f=f_fun(T[x<<1].f,T[(x<<1)+1].f);
	return i;
}
int main(){
	Int i,j,k;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++){
			cnt[i]=i-1;
			e[i].clear();
		}
		for(i=0;i<m;i++){
			scanf("%lld%lld",&j,&k);
			e[j].push_back(k);
			cnt[k]--;
		}
		build(1,1,n);
		for(i=0;i<n;i++){
			j=query(1);
			update(1,j+1,n,-1);
			for(k=0;k<(int)e[j].size();k++)update(1,e[j][k],e[j][k],1);
			printf("%lld ",j);
		}
		printf("\n");
	}
	return 0;
}