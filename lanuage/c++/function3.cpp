#include<iostream>
class string
{
	public:
		string(){str=NULL;}
		string(char *a){str=a;}
		void print();
	private:
		char *str;
};
void string::print()
{
	std::cout<<str<<std::endl<<*str;
}
int main()
{
	string a("jgvjbkj");
	void (string::*p)();
	p=&string::print;
	(a.*p)();
	return 0;
}
