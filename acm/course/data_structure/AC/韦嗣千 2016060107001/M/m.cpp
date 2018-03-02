#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int main()
{
	long int a[500000],temp,flag;
	int n,i;
	cin>>n;
	for(i=0;i<n;i++) scanf("%ld",&a[i]);
	set <long int> s(a,a+n);
	set <long int>::reverse_iterator p=s.rbegin(),q;
	while(p!=s.rend())
	{
		if(flag==*p) p++;
		temp=*p/2;
		flag=*p;
		while(temp!=0)
		{
			if(s.count(temp)==0)
			{
				s.insert(temp);
				s.erase(*p);
				break;
			}
			temp=temp/2;
		}
	}
	cout<<*s.rbegin()<<endl;
	return 0;
}