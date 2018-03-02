#include <bits/stdc++.h>
using namespace std;
class ParenthesisRemoval
{
public:
	long countWays(string s)
	{
		long remain,i,len;
		long mod=1e9+7,ans=1;
		len=s.length();
		remain=0;
		for(i=0;i<len;i++)
		{
			if(s[i]=='(')	remain++;
			else
			{
				ans=(ans*remain)%mod;
				remain--;
			}
		}
		return ans;
	}
};
int main()
{
	string s="((((())((((((((((()((((((()))))())))))()))))))))))";
	ParenthesisRemoval a;
	cout<<a.countWays(s)<<endl;
	return 0;
}