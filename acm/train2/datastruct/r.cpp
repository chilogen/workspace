#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=200010;
LL a[30],b[maxn],c[30][20],d[maxn]={0},n,m,q;
struct node{
	LL left,right,v,lazy;
	node(){v=lazy=0;}
}T[maxn<<2];
void build(LL x,LL l,LL r){
	T[x].left=l;T[x].right=r;
	if(l==r)return;
	LL mid=(l+r)>>1;
	build(x<<1,l,mid);
	build((x<<1)+1,mid+1,r);
}
void update(LL x,LL l,LL r){
	if(T[x].left>=l&&T[x].right<=r){
		T[x].lazy++;
		T[x].v++;
		return;
	}
	LL mid=(T[x].left+T[x].right)>>1;
	if(l<=mid)update(x<<1,l,r);
	if(r>mid)update((x<<1)+1,l,r);
}
void pushdown(LL x){
	T[x<<1].lazy+=T[x].lazy;
	T[x<<1].v+=T[x].lazy;
	T[(x<<1)+1].lazy+=T[x].lazy;
	T[(x<<1)+1].v+=T[x].lazy;
	T[x].lazy=0;
}
LL query(LL x,LL k){
	if(T[x].left==T[x].right)return T[x].v;
	if(T[x].lazy!=0)pushdown(x);
	LL mid=(T[x].left+T[x].right)>>1;
	if(k<=mid)return query(x<<1,k);
	else return query((x<<1)+1,k);
}
int main(){
	LL i,j,k,op,x;
	char t;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(i=0;i<26;i++){
		a[i]=i;
		c[i][0]=i;
	}
	for(i=0;i<n;i++){
		cin>>t;
		a[i]=t-'A';
		c[i][0]=a[i];
	}
	for(i=0;i<m;i++){
		cin>>t;
		b[i]=t-'A';
	}
	for(i=1;i<20;i++)
		for(j=0;j<26;j++)	
			c[j][i]=c[c[j][i-1]][i-1];
	cin>>q;
	build(1,1,m);
	while(q--){
		cin>>op;
		switch(op){
			case 1:{
				cin>>i>>j;
				update(1,i,j);
				break;
			}
			case 2:{
				cin>>i;
				d[i]++;
				break;
			}
			case 3:{
				cin>>x;
				for(i=1,k=0;i<=sqrt(x);i++){
					if(x%i==0)	k+=d[i];
					if(x%i==0&&x/i!=i)k+=d[x/i];
				}
				k+=query(1,x);
				j=b[x-1];i=0;
				while(k){
					if(k&1)j=c[j][i];
					k=k>>1;
					i++;
				}
				cout<<(char)(j+'A')<<endl;
				break;
			}
		}
	}
	return 0;
}