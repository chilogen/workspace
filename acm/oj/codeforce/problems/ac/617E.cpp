/*use mo's algorithm
*sum[x] demote the num of prefix xor sum of x between l+1 and r
*the important is in the initial l=0 and r=-1,because of the
*define above,the other thing should pay attention is the order
*of the two line in functiom upd1(mean add) and upd2(mean delete).
*when in add,we should not add x self,so we should add cnt first
*(beacuse x might equal to x^k),delete is opposite,(for example,the 
*input data is 0 0 0 0 0).
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define reset(a,b)	memset(a,b,sizeof(a))
#define MAXN 100010
struct query
{
	LL l,r,block,ind;
	bool operator <(query a)
	{
		return block==a.block?r<a.r:block<a.block;
	}
}q[MAXN];

LL l,r,n,m,k,cnt,bsize,ans[MAXN],xr[MAXN],sum[1<<20];

void upd1(LL x)
{
	cnt+=sum[x^k];
	sum[x]++;
}
void upd2(LL x)
{
	sum[x]--;
	cnt-=sum[x^k];
}

int main()
{
	LL i,j;
	reset(xr,0);
	cin>>n>>m>>k;
	bsize=sqrt(n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&j);
		xr[i]=xr[i-1]^j;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&q[i].l,&q[i].r);
		q[i].block=q[i].l/bsize;
		q[i].ind=i;
	}
	sort(q,q+m);

	l=cnt=0;	r=-1;
	for(i=0;i<m;i++)
	{
		while(r<q[i].r)		upd1(xr[r+1]),r++;
		while(r>q[i].r)		upd2(xr[r]),r--;
		while(l+1<q[i].l)	upd2(xr[l]),l++;
		while(l+1>q[i].l)	upd1(xr[l-1]),l--;
		ans[q[i].ind]=cnt;
	}
	for(i=0;i<m;i++)
		printf("%lld\n",ans[i]);
	return 0;
}