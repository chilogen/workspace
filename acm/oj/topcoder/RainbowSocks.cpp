#include <bits/stdc++.h>
using namespace std;
class RainbowSocks
{
public:
	double getPairProb(vector<int>socks,int colorDiff)
	{
		int l,i,j,k;
		double sum,a;
		l=socks.size();
		sum=l*(l-1)/2;	k=0;
		for(i=0;i<l-1;i++)
		{
			for(j=i+1;j<l;j++)
			{
				if(abs(socks[i]-socks[j])<=colorDiff)	k++;
			}
		}
		a=k;
		return k/sum;
	}
};
int main()
{
	int a[4]={1,50,50,1};
	vector<int>b(a,a+4);
	RainbowSocks c;
	cout<<c.getPairProb(b,0)<<endl;
	return 0;
}