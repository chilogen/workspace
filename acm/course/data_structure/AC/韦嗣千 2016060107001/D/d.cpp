#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
typedef struct 
{
	int x,y;
}monster;

monster *m;

struct cmp
{
	bool operator()(const monster &a,const monster &b)
	{
		if(a.y!=b.y)	return a.y>b.y;
		else return a.x>b.x;
	}
};

int ran[1000001];

int rea(int pos)
{
	int ans=0;
	while(pos)
	{
		ans+=ran[pos];
		pos-=pos&-pos;
	}
	return ans;
}

void update(int pos,int n)
{
	while(pos<=n)
	{
		ran[pos]++;
		pos+=pos&-pos;
	}
}
int main()
{
		int n,i,k,max_x=-1;
		int ans[100001];
		memset(ans,0,100001*sizeof(int));
		memset(ran,0,100001*sizeof(int));
		scanf("%d",&n);
		m=new monster[n];
		for(i=0;i<n;i++)	{scanf("%d%d",&m[i].x,&m[i].y);	if(m[i].x>max_x)	max_x=m[i].x;}
		priority_queue <monster,vector <monster>,cmp> q(m,m+n);
		while(!q.empty())
		{
			k=rea(q.top().x);
			ans[k]++;
			update(q.top().x,max_x);
			q.pop();
		}
		for(i=0;i<n;i++)	printf("%d\n",ans[i]);
		return 0;
}