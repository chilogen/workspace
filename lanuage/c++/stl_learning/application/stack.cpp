#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	stack<int> stack_int;
	stack_int.push(1);
	cout<<stack_int.size()<<endl;
	cout<<stack_int.top()<<endl;
	stack_int.pop();
	return 0;
}