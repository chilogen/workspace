#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct name
{
	string last,first;
};
bool cmp(name a,name b)
{
	if(a.last==b.last)	return a.first<b.first;
	return a.last<b.last;
}
int main()
{
	name a[101];
	LL n,i,j,k;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i].first>>a[i].last;
	sort(a,a+n,cmp);
	for(i=0;i<n;i++)
		cout<<a[i].first<<" "<<a[i].last<<endl;
	return 0;
}