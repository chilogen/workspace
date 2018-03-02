//because x no exceed 10^9,so the digtalsum
//no exceed 9*9==81
//so calc the digtal sum j from max(0,x-81) to x
//and add it to j,if equal to x,it is one of the anser

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL digtalsum(LL x)
{
	LL sum=0;
	while(x)
	{
		sum+=x%10;
		x=x/10;
	}
	return sum;
}
int main()
{
	LL x,i,j,k=0;
	vector<LL>	ans;
	cin>>x;
	i=max(x-100,0ll);
	for(j=i;j<i+100;j++)
		if(j+digtalsum(j)==x)	ans.push_back(j);
	cout<<ans.size()<<endl;
	if(ans.size())
	{
		for(i=0;i<ans.size();i++)
			cout<<ans[i]<<" ";
	}
	return 0;
}