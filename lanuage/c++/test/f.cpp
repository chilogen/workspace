#include<iostream>
using namespace std;
class String
{
	public:
		String(){p=NULL;}
		String(char *str);
		void display();
	private:
		char *p;
};
String::String(char *str)
{
	p=str;
}
void String::display()
{
	cout<<p;
}
int main()
{
	String s("sadasf");
	s.display();
	cout<<endl;
	return 0;
}
