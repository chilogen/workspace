/*
输入3个整数，用指针指向最大整数并输出
输入:
1 2 3
输出:
3
SB 
*/
#include <iostream>
using namespace std;
#define MAX(p,q)  p>q?p:q
int main()
{
	int a,b,c,d;
	int *e;
	cin>>a>>b>>c;
	d=MAX(b,c);
	d=MAX(a,d);
	if(d==a)	e=&a;
	if(d==b)	e=&b;
	if(d==c)	e=&c;
	cout<<*e;
	return 0;
}