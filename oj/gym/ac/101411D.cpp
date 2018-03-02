#include <bits/stdc++.h>
using namespace std;
#define reset(a,b)	memset(a,b,sizeof(a))
typedef long long LL;
LL a[1000010];
int main()
{
	freopen("dales.in","r",stdin);
	freopen("dales.out","w",stdout);
	LL t,n,i,j,k,l,left,right,maxhill,maxdale;
	scanf("%lld",&t);
	while(t--)
	{
		maxdale=maxhill=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=1;i<n-1;i++)
		{
			if(a[i-1]<a[i]&&a[i+1]<a[i])
			{
				left=right=i;
				while(1)
				{
					left--;	right++;
					if(left<0||right==n)	break;
					if(a[left]>=a[left+1]||a[right]>=a[right-1])	break;
				}
				right--;	left++;
				maxhill=max(maxhill,min(right-i,i-left));
			}
			else if(a[i-1]>a[i]&&a[i+1]>a[i])
			{
				left=right=i;
				while(1)
				{
					left--;	right++;
					if(left<0||right==n)	break;
					if(a[left]<=a[left+1]||a[right]<=a[right-1])	break;
				}
				right--;	left++;
				maxdale=max(maxdale,min(right-i,i-left));
			}
		}
		printf("%lld %lld\n",maxhill,maxdale);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}