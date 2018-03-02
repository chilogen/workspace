#include<iostream>
using namespace std;
class complex
{
	public:
		complex(double r,double i)
		{
			real=r;	imag=i;
		}
		complex()
		{}
		complex operator +(complex &c)
		{
			complex c1;
			c1.real=real+c.real;
			c1.imag=imag+c.imag;
			return c1;
		}
		void display()
		{
			cout<<real<<"+"<<imag<<"i"<<endl;
		}
	private:
		double real;
		double imag;
};
int main()
{
	complex c,c1(1.0,2.0),c2(2.0,3.0);
	c=c1+c2;
	c.display();
	return 0;
}
