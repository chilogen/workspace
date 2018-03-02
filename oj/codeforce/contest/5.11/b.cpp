#include <cstdio>
#include <queue>
#include <vector>

long int p[200000];
struct cmp
{
	bool operator()(const int &a,const int &b)
	{
		return p[a]>p[b];
	}
};
using namespace std;
int main()
{
	int n,i,j,k;
	long min;
	priority_queue <int,vector<int>,cmp> c[3];

	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%ld",&p[i]);
	for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		c[j-1].push(i);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		c[j-1].push(i);
	}
	scanf("%d",&n);
	while(n--)
	{
		min=-1;k=-1;
		scanf("%d",&j);
		while(!c[j-1].empty())
		{
			if(p[c[j-1].top()]==0)	c[j-1].pop();
			else {min=p[c[j-1].top()];	break;}
		}
		if(min!=-1)	{p[c[j-1].top()]=0;	c[j-1].pop();}
		printf("%ld ",min);
	}
	return 0;

}