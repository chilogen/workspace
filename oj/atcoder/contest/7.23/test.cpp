#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	bool a=(__gcd(2,4))==(__gcd(4,8));//&&__gcd(2,4)!=1;
	cout<<a;
	cout<<__gcd(2,4)<<endl<<__gcd(4,8)<<endl;
	return 0;
}