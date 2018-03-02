#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	freopen("kids.in","r",stdin);
	freopen("kids.out","w",stdout);
	double ans=0,n;
	double remain;
	LL i,j,k,m;
	cin>>n>>m;
	remain=n;
	for(i=0;i<m;i++)
	{
		ans=ans+remain/n;
		remain=remain-remain/n;
	}
	printf("%.13lf\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}