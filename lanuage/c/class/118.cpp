#include <iostream>
using namespace std;
int find(int x)
{
	if(x<100)	return 0;
	int i,j,k,l,m,num=0;
	for(m=101;m<=x;m++)
	{
		l=m;
		i=l%10;	l/=10;
		j=l%10;	l/=10;
		k=l%10;
		if(i*i*i+j*j*j+k*k*k==m)	{cout<<m<<",";num++;}
	}
	return num;
}