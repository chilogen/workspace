#include <iostream>
#include <queue>

using namespace std;
struct line
{
	int l,r;
}a[5];
struct cmp
{
	bool operator()(const line &a,const line &b)
	{
		if(a.l!=b.l)
			return a.l>b.l;
		else return a.r>b.r;
	}
};
int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)	cin>>a[i].l>>a[i].r;
	priority_queue <line, vector<line>,cmp> p(a,a+5);
	for(i=0;i<5;i++)
	{
		cout<<p.top().r<<" "<<p.top().l<<endl;
		p.pop();
	}
	return 0;
}