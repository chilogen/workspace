#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a1[1000001],a2[1000001];
struct ref
{
	LL pos,v;
}b[1000001];
bool cmpa(LL a,LL b)
{
	return a>b;
}
bool cmpb(struct ref a,struct ref b)
{
	return a.v<b.v;
}
int main()
{
	LL m,i,j,k;
	cin>>m;
	for(i=0;i<m;i++)	scanf("%lld",&a1[i]);
	for(i=0;i<m;i++)
	{
		b[i].pos=i;
		scanf("%lld",&b[i].v);
	}
	sort(a1,a1+m,cmpa);
	sort(b,b+m,cmpb);
	for(i=0;i<m;i++)	a2[b[i].pos]=a1[i];
	for(i=0;i<m;i++)	printf("%lld ",a2[i]);
	return 0;
}