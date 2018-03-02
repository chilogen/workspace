#include <bits/stdc++.h>
using namespace std;
class RangeEncoding
{
public:
	int minRanges(vector<int>arr)
	{
		int ans=1,l,i;
		l=arr.end()-arr.begin();
		for(i=0;i<l-1;i++)
		{
			if(arr[i+1]-arr[i]==1)	continue;
			ans++;
		}
		return ans;
	}
};
int main()
{
	vector<int>a;
	a.push_back(1);	a.push_back(3);
	RangeEncoding b;
	cout<<b.minRanges(a)<<endl;
	return 0;
}