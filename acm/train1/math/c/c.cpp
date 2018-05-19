#include <bits/stdc++.h>
#define PI 3.1415926535898 
using namespace std;
class point
{
public:
	double x,y;
};
class vec:public point
{
public:
	void assign(const point &a,const point &b)
	{
		x=b.x-a.x;
		y=b.y-a.y;
	}
};
point p[1001];
int operator *(const vec &a,const vec &b)
{
	double z=a.x*b.y-a.y*b.x;
	if(z>0)	return 1;
	else if(z<0) return 0;
	else if(z==0)	return 2;
}
bool cmp(const point &a,const point &b)
{
	vec v1,v2;
	v1.assign(p[0],a),v2.assign(p[0],b);
	return v1*v2;
}
double dist(const point &a,const point &b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
stack<int>s;
int main()
{
	int n,i,j,k,l,L,p0=-1,temp;
	double D1,D2;
	int D;
	vec v1,v2;
	cin>>n>>L;
	D1=2*PI*L;
	for(i=0;i<n;i++)
	{
		cin>>p[i].x>>p[i].y;
		if(p0==-1)	p0=i;
		if(p[i].y<p[p0].y)	p0=i;
		if(p[i].y==p[p0].y&&p[i].x<p[p0].x)	p0=i;
	}
	p[1000]=p[p0];	p[p0]=p[0];	p[0]=p[1000];
	sort(p+1,p+n,cmp);
	s.push(0);	s.push(1);
	for(i=2;i<n;i++)
	{
		while(1)
		{
			temp=s.top();	s.pop();
			v1.assign(p[s.top()],p[i]);	v2.assign(p[temp],p[i]);
			if(v1*v2==2)
			{
				if(dist(p[0],p[i])>dist(p[0],p[temp]))
				{
					s.push(i);	break;
				}
				else break;
			}
			if(!(v1*v2))
			{
				if(s.size()==1)
				{
					s.push(i);
					break;
				}
			}
			else
			{
				s.push(temp);
				s.push(i);
				break;
			}
		}
	}
	D2=0;
	j=s.top();	s.pop();
	D2+=dist(p[0],p[j]);
	while(!s.empty())
	{
		l=j;
		j=s.top();
		if(l==n)	l=0;
		D2+=dist(p[j],p[l]);
		s.pop();
	}
	D=(D1+D2)*10;
	if(D%10>=5)	cout<<D/10+1<<endl;
	else cout<<D/10<<endl;
	return 0;
}