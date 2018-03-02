#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
class ConsecutivePalindromes
{
public:
	LL mod=1e9+7,c[2010][2010];
	int countStrings(string s)
	{
		LL len=s.length(),ans=0,i,j;
		c[1][0]=c[1][1]=1;
		for(i=2;i<=2000;i++)
		{
			c[i][0]=1;
			for(j=1;j<=2000;j++)
				c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
		for(i=0;i<len-1;i++)
			for(j=i+1;j<len;j++)
				if(s[i]==s[j]&&check(i,j,s))
					ans=(sum(i,j,len)+ans)%mod;
		return ans;
	}
	bool check(int i,int j,string s)
	{
		while(i<j)
		{
			if(s[i]!=s[j])	return false;
			i++;	j--;
		}
		return true;
	}
	LL sum(LL a,LL b,LL len)
	{
		LL ans1=0,ans2=0,k;
		k=a;
		while(a>=0)
		{
			ans1=(ans1+c[k][a])%mod;
			a--;
		}
		k=len-b-1;	b=k;
		while(b>=0)
		{
			ans2=(ans2+c[k][b])%mod;
			b--;
		}
		if(ans1==0)	ans1=1;
		if(ans2==0)	ans2=1;
		return (ans1*ans2)%mod;
	}
};
	ConsecutivePalindromes b;
int main()
{
	string d;
	cin>>d;
	cout<<b.countStrings(d)<<endl;
	return 0;
}