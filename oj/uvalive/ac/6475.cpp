#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
void print(double ans)
{
	int i,j,k;
	k=ans*100000;	j=10000;
	if(k%10>=5)	{k=k/10+1;}
	else k=k/10;
	printf("%d.",k/j);
	k=k-(k/j)*j;
	j=j/10;
	for(i=0;i<4;i++)
	{
		printf("%d",k/j);
		k=k-(k/j)*j;
		j=j/10;
	}
}
int main()
{
	int n,i,j,k;
	double m[2],y[2],ans,one=1;
	cin>>n;
	while(n--)
	{
		cin>>m[0]>>y[0]>>m[1]>>y[1];
		if(y[1]>y[0])
		{
			ans=one/2+y[1]-y[0]-1+(one/12)*(m[1]-1);
			print(ans);
			printf("\n");
			continue;
		}
		else
		{
			ans=((one/2)/(12-m[0]+1))*(m[1]-m[0]);
			print(ans);
			printf("\n");
			continue;
		}

	}
	return 0;
}