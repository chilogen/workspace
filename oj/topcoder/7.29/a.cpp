#include <bits/stdc++.h>
using namespace std;
class ILike5
{
public:
	int transformTheSequence(vector <int> x)
	{
		int len,i,ans;
		len=x.size();
		bool havefive=false;
		ans=0;
		for(i=0;i<len;i++)
		{
			x[i]=x[i]%10;
			if(x[i]==5)	havefive=true;
		}
		for(i=0;i<len;i++)
			if(x[i]%2==0)	ans++;
		if(ans)	return ans;
		if(havefive)	return 0;
		return 1;
	}
};
int main()
{
	int a[5]={1,3};
	vector <int>b(a,a+2);
	ILike5 c;
	cout<<c.transformTheSequence(b)<<endl;
	return 0;
}