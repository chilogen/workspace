#include<iostream>
namespace com
{
	class complex
	{
		public:
			complex();
			complex(double,double);
			complex operator *(complex &c1)
			{
				complex c;
                		c.real=real*c1.real-imag*c1.imag;
             			c.imag=real*c1.imag+imag*c1.real;
             			return c;
			}
			void display();
		private:
			double real;
			double imag;
	};
	complex::complex()
	{
		real=0;
		imag=0;
	}
	complex::complex(double r,double i)
	{
		real=r;
		imag=i;
	}
	void complex::display()
	{
		if(real==0) std::cout<<imag<<"i"<<std::endl;
		else if(imag==0) std::cout<<real<<std::endl;
		else std::cout<<real<<"+"<<imag<<"i"<<std::endl;
	}
};
