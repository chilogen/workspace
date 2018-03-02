#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct cmp
{
	bool operator()(const int &a,const int &b)
	{
		return a>b;
	}
};
priority_queue <int> q1;
priority_queue <int ,vector <int>,cmp> q2;
int main(int argc, char const *argv[])
{
	int a[5]={1,2,3,4,5};
	int i;
	for(i=0;i<5;i++)
	{
		q1.push(a[i]);
		q2.push(a[i]);
	}
	for(i=0;i<5;i++)
	{
		cout<<q1.top()<<" ";
		q1.pop();
	}
	cout<<endl;
	for(i=0;i<5;i++)
	{
		cout<<q2.top()<<" ";
		q2.pop();
	}
	return 0;
}