#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
	int a[5],i;
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	set <int> s(a,a+5);
	set <int>::reverse_iterator p=s.rbegin();
	while(p!=s.rend())
		cout<<*p++<<" ";
	cout<<endl<<s.count(1); 
	return 0;
}