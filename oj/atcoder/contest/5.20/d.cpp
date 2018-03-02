#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct cmp
{
	bool operator ()(const long long int &a,const long long int &b)
	{
		return a>b;
	}
};
priority_queue <long long int>back;
priority_queue <long long int,vector <long long int>,cmp>fro;
long long int mid[100000];
long long int sum1=0,sum2=0;
long long int flag[100000];
int main(int argc, char const *argv[])
{
	int n,i,j,k,l;
	long long temp,ans,f;
	memset(flag,0,sizeof(flag));
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&temp);
		sum1+=temp;
		fro.push(temp);
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&mid[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&temp);
		sum2+=temp;
		back.push(temp);
	}
	ans=sum1-sum2;
	for(i=0;i<n;i++)
	{
		temp=fro.top();
		if(mid[i]>temp)	
		{
			sum1=sum1-temp+mid[i];
			if(sum1-sum2>ans)	ans=sum1-sum2;
			flag[i]=temp;		
			temp=mid[i];	
			fro.pop();
			fro.push(temp);

		}
	}
	for(i=n-1;i>=0;i--)
	{
		if(flag[i]!=0)
		{
			sum1=sum1-mid[i]+flag[i];
		}
		temp=back.top();
		if(mid[i]<temp)
		{
			sum2=sum2-temp+mid[i];
			if(sum1-sum2>ans)	ans=sum1-sum2;
			temp=mid[i];
			back.pop();
			back.push(temp);
		}
	}
	printf("%lld",ans);
	return 0;
}