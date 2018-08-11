#include <bits/stdc++.h>
using namespace std;
int n,a[100],b[1000],k;
struct cmp
{
	bool operator()(const int &c,const int &b)
	{
		return a[c]<a[b];
	}
};
priority_queue <int,vector<int>,cmp>q;
int main()
{
	int i,j,l;
	cin>>n>>k;
	for(i=0;i<n;i++)	cin>>a[i];
	for(i=0;i<n&&k>0;i++)
	{
		j=a[i]/2+a[i]%2;
		k-=j;	b[i]=j;
	}
	if(i!=n){printf("-1");	return 0;}
	for(i=0;i<n&&k>0;i++)
	{
		for(j=i+1;j<n&&k>0;j++)
		{
			if(b[i]<b[j]&&a[i]>a[j])
			{
				l=b[j]-b[i];
				k-=l;
				b[i]+=l;
			}
		}
	}
	if(k<0){printf("-1");	return 0;}
	for(i=0;i<n;i++)
	{
		q.push(i);
	}
	while(!q.empty()&&k>0)
	{
		i=a[q.top()]-b[q.top()];
		if(k>=i) k-=i;
		else {i=k;k=0;}
		b[q.top()]+=i;
		q.pop();
	}
	for(i=0;i<n;i++)
		cout<<b[i]<<" ";
}