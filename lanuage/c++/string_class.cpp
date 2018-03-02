/*
	*string class
		blog:http://blog.csdn.net/yzl_rex/article/details/7839379
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1,str2,str3;
	cin>>str1;
	cin>>str2;
	if(str1==str2)  cout<<"they are similar"<<endl;
		else cout<<"they are diffrernt"<<endl;
	cout<<"str1's size:"<<str1.size()<<endl;
	str3.assign(str1);
	cout<<"str3=str1="<<str3<<endl;
	return 0;
}
