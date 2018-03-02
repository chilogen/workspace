/*when we use some stl function(like sort),and if we
*we want to customize the compare rule,we usually 
*overloading operator().How did it work?
*/

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

template<class T>
class Max
{
public:
	T operator()(const T &a,const T &b)
	{
		return max(a,b);
	}
};
int main()
{
	Max<int>MAX;
	cout<<MAX(10,5);
	return 0;
}