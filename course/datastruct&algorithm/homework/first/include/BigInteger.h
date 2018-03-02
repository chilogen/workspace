#ifndef BIGINTEGER
#define BIGINTEGER

#include <bits/stdc++.h>
using namespace std;

typedef struct BigInteger
{
	vector<int>v;
	bool flag;
	BigInteger(string &s)
	{
		string::reverse_iterator p=s.rbegin();
		while(p!=s.rend())
		{
			v.push_back(*p-'0');
			p++;
		}
	}
	bool les(BigInteger &a,BigInteger &b)
	{return true;}
	string operator +(struct BigInteger &a)
	{
		string ans;
		long carryflag=0,res=0;
		vector<int>::iterator p1=a.v.begin(),p2=this->v.begin();
		while(p1!=a.v.end()&&p2!=this->v.end())
		{
			res=*p1+*p2+carryflag;
			carryflag=res/10;
			p1++,p2++;
			ans.push_back(res%10+'0');
		}
		while(p1!=a.v.end())
		{
			res=*p1+carryflag;
			ans.push_back(res%10+'0');
			carryflag=res/10;
			p1++;
		}
		while(p2!=this->v.end())
		{
			res=*p2+carryflag;
			ans.push_back(res%10+'0');
			carryflag=res/10;
			p2++;
		}
		if(carryflag)	ans.push_back(carryflag+'0');
		reverse(ans.begin(),ans.end());
		return ans;
	}

	string operator -(struct BigInteger &a)
	{
		string ans;
		BigInteger *a1,*a2;
		vector<int>::iterator p1,p2;
		bool flag=0;
		long carryflag=0,res=0;
		if(a.v.size()> this->v.size()||(a.v.size()==this->v.size()&&les(a,*this)))
			a1=&a,a2=this,flag=1;
		else a1=this,a2=&a,flag=0;
		p1=a1->v.begin();	p2=a2->v.begin();
		while(p1!=a1->v.end()&&p2!=a2->v.end())
		{
			if(*p1-carryflag<0||*p1-carryflag<*p2)
			{
				*p1=*p1-carryflag+10;
				carryflag=1;
			}
			else
			{
				*p1-=carryflag;
				carryflag=0;
			}
			ans.push_back(*p1-*p2+'0');
			p1++,p2++;
		}
		while(p1!=a1->v.end())
		{
			if(*p1-carryflag<0)
			{
				*p1=*p1-carryflag+10;
				carryflag=1;
			}
			else *p1-=carryflag;
			ans.push_back(*p1+'0');
			p1++;
		}
		string::reverse_iterator nozero=ans.rbegin();
		long k;
		while(*nozero=='0'&&nozero!=ans.rend())
		{
			nozero++;
			ans.pop_back();
		}
		if(ans.length()==0)
		{
			ans.push_back('0');
			return ans;
		}
		if(flag)	ans.push_back('-');
		reverse(ans.begin(),ans.end());
		return ans;
	}
}Integer;

bool StringProcess(string &a,string &b,string c)
{
	string::iterator p=c.begin();
	string d[2];
	bool method=0;
	int i=0;
	while(1)
	{
		if(*p=='-')	{method=true;	i++;	p++;	continue;}
		if(*p=='+')	{method=false;	i++;	p++;	continue;}
		if(*p=='=')	break;
		d[i].push_back(*p);
		p++;
	}
	a=d[0];	b=d[1];
	return method;
}

#endif