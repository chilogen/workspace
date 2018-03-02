#include <iostream>
using namespace std;
class abc
{
	public:
		int b;
		abc(int c)
		{
			b=c;
		}
		abc(abc &c)
		{
			b=c.b;
		}
		~abc()
		{
			cout<<this;
		}
};
abc fun(abc c)
{
	return c;
}
int main()
{
	abc c(2);
	fun(c);
	return 0;
}
