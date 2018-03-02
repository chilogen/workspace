#include <bits/stdc++.h>
using namespace std;
long long ans,alp[27];
void add(char c)
{
	if(c=='.')	alp[26]++;
	else alp[c-'a']++;
}
int num()
{
	int max=-1,i;
	for(i=0;i<=26;i++)
		if(alp[i]>max)	max=alp[i];
	return max;
}
int main()
{
	char a[100][100];
	int t,n,i,j,mid;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		mid=n>>1;
		for(i=0;i<n;i++)	scanf("%s",a[i]);
		for(i=0;i<=mid;i++)
		{
			for(j=i;j<=mid;j++)
			{
				memset(alp,0,sizeof(alp));
				if(i==j&&i==mid)	break;
				if(i==j)
				{
					add(a[i][j]);
					add(a[i][2*mid-j]);
					add(a[2*mid-i][j]);
					add(a[2*mid-i][2*mid-j]);
					ans+=(4-num());
				}
				else if(j==mid)
				{
					add(a[i][j]);
					add(a[2*mid-i][j]);
					add(a[j][i]);
					add(a[j][2*mid-i]);
					ans+=(4-num());
				}
				else
				{
					add(a[i][j]);
					add(a[i][2*mid-j]);
					add(a[2*mid-i][j]);
					add(a[2*mid-i][2*mid-j]);
					add(a[j][i]);
					add(a[j][2*mid-i]);
					add(a[2*mid-j][i]);
					add(a[2*mid-j][2*mid-i]);
					ans+=(8-num());
				}
			}
		}
		cout<<ans<<endl;
	}
}