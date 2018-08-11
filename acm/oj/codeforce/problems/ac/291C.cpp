/*it is important to know what is an correct subnet mask,it look like 1........0 in binary
*it means it have at least one '1' and one '0' overwall 32 bits
*we need to find an anwser contain least '1',so we start from low bit to hight bit
*change '1' to '0' bit by bit,if there have an anwser,output the last on(which will 
*contain least '1')
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL mask=((LL)1<<32)-1,n,k,a[100010][4];
LL check(LL x)
{
	LL i;
	set<LL>s;
	for(i=0;i<n;i++)
		s.insert(a[i][0]&x);
	return s.size();
}
void output(LL x)
{
	LL o[4],i,m=255;
	for(i=3;i>=0;i--)
	{
		o[i]=(x&m)>>(3-i)*8;
		m=m<<8;
	}
	for(i=0;i<3;i++)
		cout<<o[i]<<".";
	cout<<o[i]<<endl;
	exit(0);
}
int main()
{
	LL i,j,ans;
	char c;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%lld",&a[i][j]);
			c=getchar();
		}
		a[i][0]=(a[i][0]<<24)+(a[i][1]<<16)+(a[i][2]<<8)+a[i][3];
	}
	ans=-1;
	for(i=0;i<31;i++)
	{
		j=(LL)1<<i;
		mask^=j;
		if(check(mask)==k)	ans=mask;
	}
	if(ans==-1)
		cout<<"-1"<<endl;
	else output(ans);
	return 0;
}