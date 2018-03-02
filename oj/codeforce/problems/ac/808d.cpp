/*I think this problem have problem
*in the discription,it said we need to move "some"	element
*but as the tutorial said,we only need to move actually "one" element
*the ac solution in the commen http://codeforces.com/contest/808/submission/27176375
*could pass the check 113:6 \n 1 1 1 1 1000000 1000000,because it only need to move the
*last element to prefix,but it can not pass situation like this:8 \n 1 1 1 1 10 10 10 10
*because it need to move two element at least.
*I can not find a solution to solve "move some element",and i think i can be solve in poly
*time,so down there is the solvtion of "move one element"
*/ 

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL sum=0,n;
vector<LL>	a;
bool move(int rev)
{
	if(rev)	reverse(a.begin(),a.end());
	LL i,j,k;
	map<LL,LL>m;	m[0]=1;
	for(i=0,j=0;i<n;i++)
	{
		j+=a[i];
		m[a[i]]=1;
		if(j<sum)	continue;
		if(m[j-sum])	return 1;
	}
	return 0;
}
int main()
{
	LL i,j;
	cin>>n;
	for(i=0;i<n;i++)	scanf("%lld",&j),sum+=j,a.push_back(j);
	if(sum%2||n==1)	return cout<<"NO",0;
	sum=sum>>1;
	if(move(0))	return cout<<"YES",0;
	if(move(1))	return cout<<"YES",0;
				return cout<<"NO",0;
}