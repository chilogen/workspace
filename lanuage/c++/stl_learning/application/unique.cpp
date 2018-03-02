#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[10]={1,1,2,3,4,5,5,6,6,7};
	std::vector<int> v(a,a+10);
	std::vector<int>::iterator it;
	for(it=v.begin();it!=v.end();it++)
		cout<<*it<<" ";
	cout<<endl;
	unique(v.begin(),v.end());
	for(it=v.begin();it!=v.end();it++)
		cout<<*it<<" ";
	cout<<endl;
	return 0;
}