/*
	*函数重载
	*函数默认参数
	*函数模板
*/
#include<iostream>
using namespace std;
/*函数模板*/
template<typename T>
T printemplate(T v1,T v2)
{
        cout<<endl;
        cout<<v1<<"  "<<v2<<endl;
}


/*函数重载*/
void printvalue(int);
void printvalue(int,int);

/*默认参数*/
void print(int v1=10,int v2=5);
/*conflic*/
/*
void print(int v1)
{
}
void print(int v1,int v2=1)
{
}
*/
int main()
{
	printvalue(1);
	printvalue(1,2);
//function reload
	print();
	print(1);
	print(1,2);
//function default parameter
	int i1=1,i2=2;
	char c1='a',c2='b';
	printemplate(i1,i2);
	printemplate(c1,c2);
//functiom template
	return 0;
}
void printvalue(int v1)
{
        cout<<v1<<endl;
}
void printvalue(int v1,int v2)
{
        cout<<endl;
        cout<<v1<<"  "<<v2<<endl;
}

void print(int v1,int v2)
{
        cout<<endl;
        cout<<v1<<"  "<<v2<<endl;
}
