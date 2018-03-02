/*
	new&&delete
*/
#include<iostream>
using namespace std;
int main()
{
	int *i;
	char *c1,**c2;
	cout<<i<<endl;
	i=new int();
	cout<<i<<endl;
	i=new int(10);
	cout<<i<<"  "<<*i<<endl;
	delete i;
	cout<<i<<endl;
	i=new int();
	cout<<i<<endl;
	return 0;
}
