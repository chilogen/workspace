#include <iostream>
#include <string>
using namespace std;
class AB
{
    public:
    string createString(int n,int k)
    {
        string a(n,'B'),empty;
		int pos=0,numa=0;
		while(pos<n&&k>0)
		{
			while(n-pos>k)
				pos++;
		}
		if(k>0)	return empty;
		return a;
	}
};
int main()
{
	AB abc;
	string a;
	a=abc.createString(10,12);
	cout<<a;
	return 0;
}