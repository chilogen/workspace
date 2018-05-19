#include <stdio.h>
int set[100001]={0};
long long int power[100001],sum[100001]={0};

int find(int x)
{
	if(set[x]==0)	return 0;
	if(x==set[x])	return x;
	set[x]=find(set[x]);
	sum[x]=sum[set[x]];
	return set[x];
}

int main()
{
	int n;
	long long int ans[100000]={0};
	int order[100000];
	long long int max=0;
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&power[i]);
	}
	for(i=0;i<n;i++)	scanf("%d",&order[i]);
	for(j=i-1;j>=0;j--)
	{
		int left,right,left_fat,right_father;
		long long a,b,c;
		if(order[j]+1<=n)	right=order[j]+1;	else right=order[j];
		if(order[j]-1>=1)	left=order[j]-1;	else left=order[j];
		left_fat=find(left);	right_father=find(right);
		if(left_fat==0)	a=0;	else {a=sum[left_fat];	set[left_fat]=order[j];}
		if(right_father==0)	b=0;	else {b=sum[right_father];	set[right_father]=order[j];}
		c=power[order[j]];
		set[order[j]]=order[j];
		sum[order[j]]=a+b+c;
		if(sum[order[j]]>max)	max=sum[order[j]];
		ans[j]=max;
	}
	for(j=1;j<i;j++)	printf("%lld\n",ans[j]);
	printf("0\n");
	return 0;
}