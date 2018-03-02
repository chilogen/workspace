#include <iostream>
#include <string>
using namespace std;
bool output(string prefix,string middle,string &suffix)
{
	int pos=-1;
	pos=middle.find(prefix[0]);
	if(pos==-1)	return false;
	if(middle.length()==1)
	{
		if(prefix[0]==middle[0])
		{
			suffix.push_back(prefix[0]);
			return true;
		}
		return false;
	}
	output(prefix.substr(1,prefix.length()-1),middle.substr(0,pos),suffix);
	output(prefix.substr(pos+1,prefix.length()-pos-1),middle.substr(pos+1,middle.length()-pos-1),suffix);
	suffix.push_back(prefix[0]);
	return true;
}
int main()
{
	string prefix,middle,suffix;
	cin>>prefix>>middle;
	if(prefix.length()!=middle.length()||!output(prefix,middle,suffix))	cout<<"error"<<endl;
	else cout<<suffix<<endl;;
	return 0;
}