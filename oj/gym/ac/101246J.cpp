#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
double l;
double dis,rig,shift=(double)1e15;
double buoys[410],tmp[410],ans[410];
inline void eq(double *a,double *b)
{
	LL i,j,k;
	for(i=0;i<n;i++)
		a[i]=b[i];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	LL i,j,k;
	cin>>n;
	for(i=0;i<n;i++)
		scanf("%lf",&buoys[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			dis=(buoys[j]-buoys[i])/(j-i);
			l=0;
			for(k=0;k<n;k++)
			{
				rig=buoys[i]-dis*(i-k);
				if(!(abs(rig-buoys[k])<1e-9))
				{
					l=l+abs(rig-buoys[k]);
				}
				tmp[k]=rig;
				
			}
			if(l<shift)	{eq(ans,tmp);	shift=l;}
		}
	}
	printf("%.4lf\n",shift);
	for(i=0;i<n;i++)
	{
		printf("%.10lf ",ans[i]);
	}
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}