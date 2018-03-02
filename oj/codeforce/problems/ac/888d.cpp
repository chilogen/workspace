/*we need to find the number of permutation 1~n that have 
*least (n minus k)'s position p[i]=i.
*just forget that problem a moment.if every player have his own shit
*in the lounge,after the game,you are the one who look after those shit
*so after the game,you should give everyone his owm shit,but you want to
*make a joke,just every on can gave his own shit.how many way to do it?
*you can pick p1 a random shit not belong to he(if it is p2's shit),it have
*n-1 choice,and then you give a random shit to p2(now you can give any shit to
*he,because his shit have been give to p1),so you also have n-1 choice.
*now,just let m[x] identity the number that the number of method to give everyone
*shit no belong to him,so m[x]=m[x-2](give p2 p1's shit)+(x-2)*dp[x-2](do not give
*p2 p1's shit),and the dp[i]=dp[i-1]+(i-2)*m[i-1](give p3 p1's shit and don't give
*p3 p1's shit),it just the mean of m in the code.
*
*now go back the problem,we can choose x positions that p[i]=i,and let the reamin
*positions p[i]!=i,just add x from n-k to n,we can get the answer.we can use the
*method above to get the num of p[i]!=i,and use combination to get the num of p[i]=i
*luckly in this problem,1<=k<=4,so we can calculate m first use brute force but not
*recursive.
//brute force:

	int cnt=0,a[10],i,n;
	cin>>n;
	for(i=0;i<n;i++)	a[i]=i;
	do
	{
		for(i=0;i<n;i++)
			if(a[i]==i)	break;
		if(i==n)	cnt++;
	}while(next_permutation(a,a+n));
	cout<<cnt<<endl;
*that is why m[6]={0,0,1,2,9,44};	
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ans=0,n,k,c[1010][1010]={0},m[6]={0,0,1,2,9,44};
int main()
{
	LL n,k,i,j;
	cin>>n>>k;
	c[0][0]=1;
	for(i=1;i<=1000;i++)
	{
		c[i][0]=1;
		for(j=1;j<=i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	for(j=n-k;j<=n-2;j++)
	{
		ans+=c[n][j]*m[n-j];
	}
	ans++;
	cout<<ans<<endl;
	return 0;
}