//runtime error
#include <bits/stdc++.h>
using namespace std;
typedef struct
{
	double s,e;
}seg;
typedef struct 
{
	int s,e,max,lazy;
}tree;
tree T[100000<<5];
seg t[100001];
double w,h,x,y,vx,vy,INF=9999999999;
inline void getse(int i)
{
	if((vx==0&&(x==0||x==h))||(vy==0&&(y==0||y==h)))
	{
		t[i].s=t[i].e=INF;
		return;
	}
	double t1=-(x/vx),t2=-(y/vy),t3=(w-x)/vx,t4=(h-y)/vy;
	if(vx<0&&vy>0)
	{
		t[i].s=max(t3,t2);
		t[i].e=min(t1,t4);
	}
	else if(vx>0&&vy<0)
	{
		t[i].s=max(t1,t4);
		t[i].e=min(t2,t3);
	}
	else if(vx<0&&vy<0)
	{
		t[i].s=max(t3,t4);
		t[i].e=min(t1,t2);
	}
	else
	{
		t[i].s=max(t1,t2);
		t[i].e=min(t3,t4);
	}
	t[i].s=max(0.0,t[i].s);
	if(abs(t[i].s-t[i].e)<1e-6||t[i].e<t[i].s)	t[i].e=t[i].s=INF;
}
bool cmp(double a,double b){return abs(a-b)<1e-6;}
void build(int s,int e,int x)
{
	T[x].s=s;	T[x].e=e;
	if(s==e)
	{
		T[x].max=0;
		return ;
	}
	int mid=(s+e)>>1;
	build(s,mid,x<<1);
	build(mid+1,e,(x<<1)+1);
}
void insert(int s,int e,int v,int x)
{
	if(s<=T[x].s&&e>=T[x].e)
	{
		T[x].lazy+=v;
		T[x].max+=v;
		return ;
	}
	int mid=(T[x].s+T[x].e)>>1;
	if(mid<s)	insert(s,e,T[x].lazy+v,(x<<1)+1);
	else if(mid>=e)	insert(s,e,T[x].lazy+v,x<<1);
	else
	{
		insert(s,e,T[x].lazy+v,(x<<1)+1);
		insert(s,e,T[x].lazy+v,x<<1);
	}
	T[x].max=max(T[x<<1].max,T[(x<<1)+1].max);
	T[x].lazy=0;
}
int main()
{
	int kase,i,j,k,n;
	vector<double>vec,hash;
	vector<double>::iterator p;
	map<double,int>m;
	cin>>kase;
	while(kase--)
	{
		m.clear();
		vec.clear();
		memset(T,0,sizeof(T));
		cin>>w>>h>>n;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&x,&y,&vx,&vy);
			getse(i);
			if(t[i].s!=INF&&t[i].e!=INF)
			{
				vec.push_back(t[i].s);
				vec.push_back(t[i].e);
			}
		}
		hash=vec;
		sort(hash.begin(),hash.end());
		p=unique(hash.begin(),hash.end(),cmp);
		build(1,p-hash.begin(),1);
		hash.resize(p-hash.begin());
		for(p=hash.begin();p!=hash.end();p++)
			m[*p]=p-hash.begin()+1;
		for(p=vec.begin();p!=vec.end();p=p+2)
			insert(m[*p],m[*(p+1)],1,1);
		cout<<T[1].max<<endl;
	}
	return 0;
}