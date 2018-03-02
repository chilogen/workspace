#include<stdio.h>
void  bubbleSort(int data[],int n)
{
	int lop,loop,t;
	for(lop=0;lop<n;lop++)
	{
		for(loop=lop;loop<n;loop++)
		{
			if(data[lop]<data[loop])
			{
				t=data[lop];
				data[lop]=data[loop];
				data[loop]=t;
			}
		}
	}
}
int main()
{
	int a[5]={1,3,9,4,2};
	bubbleSort(&a[0],5);
	for(int lop=0;lop<5;lop++)
	printf("%d ",a[lop]);
	return 0;
}
