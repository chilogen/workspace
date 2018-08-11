#include <bits/stdc++.h>
using namespace std;
int a[5][5];
int main()
{
	int i,j;
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
			scanf("%d",&a[i][j]);
	int left,stright,right,ac=0;
	for(i=1;i<=4;i++)
	{
		left=i-1;
		if(left==0)	left=4;
		right=i+1;
		if(right==5)	right=1;
		stright=i+2;
		if(stright>4)
		stright-=4;
		if(a[i][1]&&a[left][4])	{ac=1;break;}
		if(a[i][2]&&a[stright][4])	{ac=1;break;}
		if(a[i][3]&&a[right][4])	{ac=1;break;}
		if((a[i][1]&&a[i][4])||(a[i][2]&&a[i][4])||(a[i][3]&&a[i][4]))	{ac=1;break;}
	}
	if(ac)	printf("YES");
	else printf("NO");
	return 0;
}