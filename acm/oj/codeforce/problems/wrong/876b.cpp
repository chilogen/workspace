//TLE38

#include <bits/stdc++.h>
using namespace std;
int a[100010],used[100010];
int main()
{
	int n,k,m,i,j,l,base;
	vector<int> v;
	vector<int>::iterator p;
	cin>>n>>k>>m;
	for(i=0;i<n;i++)	cin>>a[i];
	memset(used,0,sizeof(used));
	l=0;
	while(l<n)
	{
		v.clear();
		for(i=0;i<n;i++)	if(!used[i])	break;
		j=0;	base=a[i];
		while(j<k&&i<n)
		{
			if(used[i])
			{
				i++;
				continue;
			}
			if((a[i]-base)%m==0)
			{
				used[i]=1;
				v.push_back(a[i]);
				j++;
				l++;
			}
			i++;
		}
		if(j==k)
		{
			cout<<"Yes"<<endl;
			for(p=v.begin();p!=v.end();p++)
				cout<<*p<<" ";
			return 0;
		}
		if(n-l<k)	break;
	}
	cout<<"No"<<endl;
	return 0;
}