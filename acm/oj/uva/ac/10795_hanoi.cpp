#include <bits/stdc++.h>
using namespace std;
void hanoi(char a,char b,char c,int n)
{
	if(n==1)	{//cout<<a<<"->"<<c<<endl;	
	return;}
	hanoi(a,c,b,n-1);
	//cout<<a<<"->"<<c<<endl;
	hanoi(b,a,c,n-1);
}
int main()
{
	int n;
	cin>>n;
	hanoi('a','c','b',n-1);
	//cout<<"a->c"<<endl;
	hanoi('b','a','c',n-1);
}