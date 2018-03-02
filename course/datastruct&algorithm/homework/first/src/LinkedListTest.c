#include "../include/LinkedList.h"
#include "../include/LinkedListFun.h"
#include "../include/Status.h"
#include <stdio.h>


int main()
{
	long a[10],i,j,k;
	SingleListPtr l;
	Status status=fail;
	printf("Creat SingleList:\n");
	for(i=0;i<10;i++)	scanf("%ld",&a[i]);
	SingleListCreate(&l,a,10);
	printf("now,those elem in List:\n");
	SingleListPrint(l);
	printf("locate an elem x's position:\nEnter x:\n");
	while(status!=success)
	{
		scanf("%ld",&i);
		status=SingleListLocate(l,i,&j);
		if(status==success)	printf("elem %ld in pos %ld\n",i,j);
		else if(status==fail)	printf("can't find this elem,try another:\n");
	}	
	status=fail;
	printf("get the position x's elem:\nEnter x:\n");
	while(status!=success)
	{
		scanf("%ld",&i);
		status=SingleListRetrive(l,i,&j);
		if(status==success)	printf("elem %ld in position %ld\n",j,i);
		else if(status==range_error)	printf("range_error,reEnter:\n");
	}
	printf("Insert an elem x before position y:Enter x&&y:\n");
	status=fail;
	while(status!=success)
	{
		scanf("%ld%ld",&i,&j);
		if(j<1)
		{
			printf("range_error,reEnter\n");
			continue;
		}
		status=SingleListInsert(l,j,i);
		if(status==success)
		{
			printf("Insert success,List now is:\n");
			SingleListPrint(l);
		}
		else if(status==range_error)	printf("range_error,reEnter\n");
	}
	/*
	SingleListCreate(&l,a,10);
	SingleListPrint(l);
	//Status SingleListRetrive(SingleListPtr L,long pos,long * value)
	//Status SingleListLocate(SingleListPtr L,long value,long * pos)
	//Status SingleListInsert(SingleListPtr L,long pos,long value)
	SingleListInsert(l,6,54);
	SingleListPrint(l);
	printf("%ld\n",i);
	*/
	return 0;
}
