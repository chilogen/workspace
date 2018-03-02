/*we can know that the slope of ray can only be 1 and -1,
*so at first, we can demote a point as y=x+b and y=-x+b,use two array p[0] and p[2]
*to store it. and then used adjacency table(function connect) to save
*the index of point.
*let the ray start at v(1,1) and x=0,y=0,use x,y and v,we can calculate k and b,
*use k,b and adjacency table to locate the point and calculate the time.
*in a n*m rectange,the ray can not turn it's direction above n+m,so the complxity
*is O(k*(n+m)),while k demote the largest num of point in a straigh line

*i face a confuse problem when i was debuging, it get a wrong answer at big data range
*finally i find the bug:
*to storage imposite value of b,i add a MAX to it,but i do a wrong calc,it shout use
*memrary space of 4*MAX,not 2*MAX,so "used array's data will be seem as usedray array"
*so the program would terminate before finish the job
*/

#include <bits/stdc++.h>
using namespace std;
#define reset(a,b)	memset(a,b,sizeof(a))
#define MAXN 100010l 
//#define MAX (MAXN-1)
typedef long long ll;

ll MAX=MAXN-1;

struct point
{
	ll b,ind,x,y;
}p[2][MAXN];

ll fir[2][4*MAXN],nex[2][4*MAXN],ans[MAXN],n,m,k,size;
bool usedray[2][MAXN*4],used[MAXN];

inline void connect(ll x,ll i,ll k)
{
	x+=MAX;
	if(fir[k][x]!=-1)	nex[k][i]=fir[k][x];
	fir[k][x]=i;
}


void nextray(pair<ll,ll>&v,ll &x,ll &y,ll &time)
{
	ll tempx,tempy,t;
	if(v.first==-1)	tempx=x;
	else tempx=n-x;
	if(v.second==-1)	tempy=y;
	else tempy=m-y;
	t=min(tempx,tempy);
	x+=t*v.first;	y+=t*v.second;
	if(x==n||x==0)	v.first*=-1;
	if(y==m||y==0)	v.second*=-1;
	time+=t;
}

void fill(pair<ll,ll> &v,ll &x,ll &y,ll &time,ll f)
{
	ll k=v.first*v.second,b=y-k*x,nowpoint=fir[f][b+MAX],t;
	point &a=p[f][nowpoint];
	if(!used[a.ind])
	{
		used[a.ind]=1;
		size++;
		t=(a.x-x)/v.first;
		ans[a.ind]=time+t;
		nowpoint=nex[f][nowpoint];
	}
	while(nowpoint!=-1)
	{
		point &a=p[f][nowpoint];
		if(!used[a.ind])
		{
			used[a.ind]=1;
			size++;
			t=(a.x-x)/v.first;
			ans[a.ind]=time+t;
		}
		nowpoint=nex[f][nowpoint];
	}            
}
int main()
{
	ll i,j,l,x,y,b,time;
	cin>>n>>m>>k;
	reset(fir,-1),reset(nex,-1),reset(ans,-1),reset(used,0),reset(usedray,0);
	for(i=0;i<k;i++)
	{
		scanf("%lld%lld",&x,&y);
		p[0][i].ind=p[1][i].ind=i;
		p[0][i].x=p[1][i].x=x;
		p[0][i].y=p[1][i].y=y;
		p[0][i].b=y-x;
		p[1][i].b=y+x;
		connect(p[0][i].b,i,0);
		connect(p[1][i].b,i,1);
	}                    
	pair<ll,ll>v=make_pair(1,1);
	j=k;	time=0;	x=y=0;
	k=v.first*v.second;	b=y-k*x;
	i=0;
	while(size<j)
	{
		i++;
		if(k>0&&fir[0][b+MAX]!=-1)
		{
			if(usedray[0][b+MAX])	break;
			fill(v,x,y,time,0);
			usedray[0][b+MAX]=1;
		}
		else if(k<0&&fir[1][b+MAX]!=-1)
		{
			if(usedray[1][b+MAX])	break;
			fill(v,x,y,time,1);
			usedray[1][b+MAX]=1;
		}
		nextray(v,x,y,time);
		k=v.first*v.second;	b=y-k*x;
	}
	for(i=0;i<j;i++)
		cout<<ans[i]<<endl;
	return 0;
}