/*it is hard to read  the question!!!so get some example
*oooo	1
*xooo->ooox 2
*ooox	1
*xoxo->(oxxo->oxox)->oxox  3
*it is easy to find some law,juse use disjoint set to store 
*data in the most right cell,and then just calc it
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct ss
{
	LL num,fat,status;
}a[300010];
LL getf(long x)
{
	if(a[x].fat==x)	return x;
	else return a[x].fat=getf(a[x].fat);
}
int main()
{
	memset(a,0,sizeof(a));
	LL n,i,j,k,l,sum=1;
	cin>>n;
	a[n+1].status=-1;
	cout<<"1 ";
	for(i=1;i<=n+1;i++)	a[i].fat=i;
	for(i=1;i<n;i++)
	{
		scanf("%lld",&k);
		long f=getf(k+1);
		if(a[f].status==-1)
		{
			sum-=a[k-1].num;
			a[k].fat=f;
			if(a[k-1].status==1)
				a[k-1].fat=a[k].fat;
		}
		else if(a[f].status==0)
		{
			sum++;
			if(a[k-1].status==1)
				a[k-1].fat=a[k].fat;
			a[k].num=a[k-1].num+1;
			a[k].status=1;
		}
		else if(a[f].status==1)
		{
			sum++;
			a[k].fat=f;
			if(a[k-1].status==1)
				a[k-1].fat=a[k].fat;
			a[f].num+=(a[k-1].num+1);
		}
		cout<<sum<<" ";
	}
	cout<<"1"<<endl;
	return 0;
}