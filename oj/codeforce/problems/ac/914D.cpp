#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;
struct node{
	int l,r;
	int gcd;
	node(){l=r=-1;}
}s[MAXN<<5];
int a[MAXN],n,l,r,x;
int godown(int x,int v){
	if(s[x].l==s[x].r){
		if(s[x].gcd%v==0)	return 0;
		else return 1;
	}
	int ans=0;
	if(s[x<<1].l!=-1&&s[x<<1].gcd%v!=0)	ans+=godown(x<<1,v);
	if(ans>1)	return 2;
	if(s[(x<<1)+1].l!=-1&&s[(x<<1)+1].gcd%v!=0)ans+=godown((x<<1)+1,v);
	return ans;

}
int build(int q,int e,int x){
	int mid=(q+e)>>1;
	s[x].l=q;	s[x].r=e;
	if(q==e)	s[x].gcd=a[q];
	else	s[x].gcd=__gcd(build(q,mid,x<<1),build(mid+1,e,(x<<1)+1));
	return s[x].gcd;
}
void change(int q,int e,int x){
	if(s[x].l==s[x].r)	s[x].gcd=e;
	else{
		int mid=(s[x].l+s[x].r)>>1;
		if(q<=mid)	change(q,e,x<<1);
		else change(q,e,(x<<1)+1);
		s[x].gcd=__gcd(s[x<<1].gcd,s[(x<<1)+1].gcd);
	}
}
int query(int q,int e,int v,int x){
	if(s[x].l>=q&&s[x].r<=e){
		if(s[x].gcd!=v)	return godown(x,v);
		else return 0;
	}
	int mid=(s[x].l+s[x].r)>>1,ans=0;
	if(q<=mid)	ans+=query(q,e,v,x<<1);
	if(e>mid)	ans+=query(q,e,v,(x<<1)+1);
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	int i,j,k,l,q,x;
	cin>>n;
	for(i=1;i<=n;i++)	cin>>a[i];
	build(1,n,1);
	cin>>q;
	while(q--){
		cin>>i;
		if(i==1){
			cin>>j>>k>>l;
			x=query(j,k,l,1);
			if(x==1||x==0)	cout<<"YES"<<endl;
			else	cout<<"NO"<<endl;
		}
		else{
			cin>>j>>k;
			change(j,k,1);
		}
	}
}