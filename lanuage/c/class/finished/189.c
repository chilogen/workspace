#include<stdio.h>
int a[100];
int find(int start,int end,int f)
{
	int i=(start+end)/2;
	if(a[i]==f) return i;
	else if(a[i]<f) return(find(i,end,f));
	else return(find(start,i,f));
}
int main()
{
	int n,f;
	scanf("%d",&n);
	for(int lop=0;lop<n;lop++)
	{
		scanf("%d,",&a[lop]);
	}
	scanf("%d",&f);
	printf("%d",find(0,n,f)+1);
	return 0;
}
