#include <bits/stdc++.h>
using namespace std;
class TransformTheTree
{
public:
	int countCuts(vector <int> parents)
	{
		int len=parents.size(),i,j,l,ans=0;
		int con[60];
		memset(con,0,sizeof(con));
		for(i=1;i<=len;i++)
		{
			con[i]++;
			con[parents[i-1]]++;
		}
		for(i=0;i<=len;i++)
		{
			if(con[i]>2)	ans+=(con[i]-2);
		}
		return ans;
	}
};
int main()
{
	int a[13]={0, 1, 2, 0, 4, 5, 6, 4, 5, 6, 0, 11, 12};
	vector<int>b(a,a+13);
	TransformTheTree c;
	cout<<c.countCuts(b)<<endl;
	return 0;
}