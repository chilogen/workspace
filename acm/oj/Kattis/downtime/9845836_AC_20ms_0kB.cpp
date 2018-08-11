#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100010];
int main()
{
	LL n,k,remain,mac,i,j;
	queue<LL>q;
	cin>>n>>k;
	mac=1;
	remain=k;
	for(i=0;i<n;i++)	scanf("%lld",&a[i]);
	sort(a,a+n);
	q.push(a[0]);	remain--;
	for(i=1;i<n;i++)
	{
		j=q.front();
		while(j+1000<=a[i]&&!q.empty())
		{
			q.pop();
			remain++;
			if(q.empty())	break;
			j=q.front();
		}
		if(remain>0)
		{
			q.push(a[i]);
			remain--;
		}
		else
		{
			mac++;
			remain+=k;
			q.push(a[i]);
			remain--;
		}
	}
	cout<<mac<<endl;
	return 0;
}