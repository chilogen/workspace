#ifndef ERROR_H
#define ERROR_H

#include <iostream>
using namespace std;
void error(int num)
{
	switch(num)
	{
		case 1:
		{
			cerr<<"can't open file"<<endl;
			exit(0);
		}
		case 2:
		{
			cerr<<"file damage"<<endl;
			exit(0);
		}
		case 3:
		{
			cerr<<"wrong use of open"<<endl;
			exit(0);
		}
		case 4:
		{
			cerr<<"wrong process of file"<<endl;
			exit(0);
		}
		case 5:
		{
			cerr<<"wrong use of zzip"<<endl;
			exit(0);
		}
	}
}

#endif