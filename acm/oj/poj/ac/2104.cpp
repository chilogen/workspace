#include <bits/stdc++.h>
using namespace std;
#define lson l,m
#define rson m+1,r
typedef long long LL;
const long long N=1e5;
LL L[N<<5],R[N<<5],C[N<<5],T[N<<5];
LL a[N],Hash[N],tot=0;
void build(LL l,LL r)
{
	if(l==r)	return;
	LL m=(l+r)>>1;
	LL rt=tot-1;
	L[rt]=tot++;
	build(lson);
	R[rt]=tot++;
	build(rson);
}
void update(LL pre,LL l,LL r,LL x)
{
	LL m=(l+r)>>1,rt=tot-1;
	L[rt]=L[pre];	R[rt]=R[pre];	C[rt]=C[pre]+1;
	if(l==r)	return ;
	if(x<=m)
	{
		L[rt]=tot++;
		update(L[pre],lson,x);
	}
	else
	{
		R[rt]=tot++;
		update(R[pre],rson,x);
	}
}
LL query(LL rt1,LL rt2,LL l,LL r,LL x)
{
	if(r==l)	return r;
	LL num=C[L[rt2]]-C[L[rt1]],m=(l+r)>>1;
	if(num>=x)
		return query(L[rt1],L[rt2],lson,x);
	else return query(R[rt1],R[rt2],rson,x-num);
}
int main()
{
	LL n,q,i,j,k,l,len;
	cin>>n>>q;
	for(i=0;i<n;i++)	
	{
		cin>>a[i];
		Hash[i]=a[i];
	}
	sort(Hash,Hash+n);
	len=unique(Hash,Hash+n)-Hash;
	T[0]=tot++;
	build(1,len);
	for(i=0;i<n;i++)
	{
		j=lower_bound(Hash,Hash+len,a[i])-Hash+1;
		T[i+1]=tot++;
		update(T[i],1,len,j);
	}
	for(i=0;i<q;i++)
	{
		cin>>j>>k>>l;
		l=query(T[j-1],T[k],1,len,l);
		cout<<Hash[l-1]<<endl;
	}
	return 0;
}