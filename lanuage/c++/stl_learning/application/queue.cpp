#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	deque <int>::iterator p,m;
	deque <int> que;
	int i;

	for(i=0;i<20;i++)
	{
		que.push_front(i);
	}

	p=que.begin()+10;
	m=que.end();

	deque <int> que2(p,m);

	for(p=que2.begin();p!=que2.end();p++)
	{
		cout<<*p<<endl;
	}
	return 0;
}