#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main()
{
	string s[]={"abc","cde","efg"};
	vector <string> vec(s,s+3);
	vector <string>::iterator p=vec.begin();
	while(p!=vec.end())
		cout<<*p++<<endl;



	vector <string> v2(vec);
	cout<<v2.at(2)<<endl;



	vector <string> v3;
	v3.assign(s,s+3);
	p=v3.begin();
	while(p!=v3.end())
			cout<<*p++<<endl;
	

	int a[5]={1,2,3,4,5};
	vector <int> v4;
	v4.assign(a,a+5);
	copy(v4.begin(),v4.end(),ostream_iterator<int>(cout,"a"));
	v4.assign(50,12);
	copy(v4.begin(),v4.end(),ostream_iterator<int>(cout," "));
	return 0;
}