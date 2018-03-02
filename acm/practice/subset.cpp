#include <bits/stdc++.h>
using namespace std;
void subset(int n,int *a,int cur)
{
	int i;
	for(i=0;i<cur;i++)	cout<<a[i]<<" ";
	cout<<endl;
	int s;
	if(cur==0)	s=0;
	else s=a[cur-1]+1;
	for(i=s;i<n;i++)
	{
		a[cur]=i;
		subset(n,a,cur+1);
	}
}
int main()
{
	int a[5]={0};
	subset(5,a,0);
	return 0;
}
