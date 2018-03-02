#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define dataset 5
typedef long long ll;

struct even
{
	ll start,end;
}e[MAXN];
bool cmp(even a,even b){return a.end<b.end;}
ll even_num;

inline void fill(ll *a,ll i,ll j,ll k)
{
	for(;i<k;i++)	a[i]=j;
}

//method1,01 pack
ll method1()
{
	ll i,j,k;
	//discretization the even time
	vector<ll>v;
	vector<ll>::iterator p;
	map<ll,ll>m;
	for(i=0;i<even_num;i++)
	{
		v.push_back(e[i].start);
		v.push_back(e[i].end);
	}
	sort(v.begin(),v.end());
	p=unique(v.begin(),v.end());
	v.resize(p-v.begin());
	for(p=v.begin();p!=v.end();p++)
		 m[*p]=p-v.begin();
	//end of discretization even time

	//ll dp[MAXN*2]={0};//dp[i] demote at the even(x)'s end time,the maxnum of even can be hold
	ll *dp=new ll[v.size()];

	for(i=0;i<even_num;i++)
	{
		dp[m[e[i].end]]=max(dp[m[e[i].end]],dp[m[e[i].start]]+1);//that is the point
		fill(dp,m[e[i].end],dp[m[e[i].end]],v.size());// make all time after e[i].end equal to time e[i].end
	}

	return dp[v.size()-1];
}


void input()
{
	cin>>even_num;
	ll i,j,k;
	for(i=0;i<even_num;i++)
		cin>>e[i].start>>e[i].end;
	sort(e,e+even_num,cmp);
}
int main()
{
	ll i;
	for(i=0;i<dataset;i++)
	{
		input();
		cout<<method1()<<endl;
	}
	return 0;
}