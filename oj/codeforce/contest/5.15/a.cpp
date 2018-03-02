#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,i,j=1;
	cin>>n;
	if(n<10){printf("1");return 0;}
	else
	{
		i=n/10;
		j=j*10;
		while(i>=10)
		{
			i=i/10;
			j=j*10;
		}
		cout<<(i+1)*j-n;
	}
	return 0;
}