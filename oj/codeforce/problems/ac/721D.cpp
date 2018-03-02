#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct val
{
	LL v,Abs,ind;
};
struct cmp
{
	bool operator()(val a,val b){return a.Abs>b.Abs;}
};
bool cmp1(val a,val b)
{
	return a.ind<b.ind;
}
priority_queue<val,vector<val>,cmp> q;
LL n,k,x,neg;
inline void fun(LL m,val &tmp)
{
	tmp.v+=m;
	tmp.Abs=abs(tmp.v);
}
int main()
{
	LL i,j;
	val tmp;
	ios::sync_with_stdio(false);
	cin>>n>>k>>x;
	for(i=0;i<n;i++)
	{
		cin>>tmp.v;
		if(tmp.v<0)	neg++;
		tmp.Abs=abs(tmp.v);
		tmp.ind=i;
		q.push(tmp);
	}
	while(k--)
	{
		tmp=q.top(),q.pop();
		if(neg%2==0)
		{
			if(tmp.v<0)
			{
				fun(x,tmp);
				if(tmp.v>=0)	neg--;
			}
			else if(tmp.v>=0)
			{
				fun(-x,tmp);
				if(tmp.v<0)	neg++;
			}
		}
		else
		{
			if(tmp.v<0)	fun(-x,tmp);
			else fun(x,tmp);
		}
		q.push(tmp);
	}
	vector<val>v;
	while(!q.empty())
	{
		v.push_back(q.top());
		q.pop();
	}
	sort(v.begin(),v.end(),cmp1);
	for(i=0;i<n;i++)
		cout<<v[i].v<<" ";
	return 0;
}