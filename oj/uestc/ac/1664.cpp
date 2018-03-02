#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL left,mul,bobs,i,j,k,l;
	string p;
	stack<LL>s;
	cin>>p>>bobs;
	s.push(p[0]-'0');
	left=p[0]-'0';
	for(i=1;i<p.length()-1;i=i+2)
	{

		if(p[i]=='+')
		{
			left=left+(p[i+1]-'0');
			s.push(p[i+1]-'0');
		}
		if(p[i]=='*')
		{
			left=left*(p[i+1]-'0');
			j=s.top();	s.pop();
			k=p[i+1]-'0';
			s.push(j*k);
		}
	}
	mul=0;
	while(!s.empty())
	{
		mul=mul+s.top();
		s.pop();
	}
	if(mul==bobs&&left!=bobs)
		cout<<"M"<<endl;
	else if(mul!=bobs&&left==bobs)
		cout<<"L"<<endl;
	else if(mul==bobs&&left==bobs)
		cout<<"U"<<endl;
	else if(mul!=bobs&&left!=bobs)
		cout<<"I"<<endl;
	return 0;
}