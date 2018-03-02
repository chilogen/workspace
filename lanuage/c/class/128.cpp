#include <iostream>
using namespace std;
int main()
{
	double ans=0,i=1;;
	long step;
	while(i>1e-8)
	{
		step++;
		i=1/(double)(2*step-1);
		if(step%2)	ans+=i;
		else ans-=i;
	}
	cout<<"steps="<<step<<" "<<"PI="<<ans*4;
	return 0;
}